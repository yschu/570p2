
-- MOESI 3-hop protocol

----------------------------------------------------------------------
-- Constants

----------------------------------------------------------------------
const
  ProcCount: 3;          -- number processors
  ValueCount:   1;       -- number of data values.
  VC0: 0;                -- low priority
  VC1: 1;
  VC2: 2;
  QMax: 2;
  NumVCs: VC2 - VC0 + 1;
  NetMax: ProcCount+20;
  

----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type
  Proc: scalarset(ProcCount);   -- unordered range of processors
  Value: scalarset(ValueCount); -- arbitrary values for tracking coherence
  Home: enum { HomeType };      -- need enumeration for IsMember calls
  Node: union { Home , Proc };

  VCType: VC0..NumVCs-1;
  AckType: -ProcCount..ProcCount;

  MessageType: enum {  GetS,         -- request for being share state
                       GetData,      -- get data (w/ data and ackNumber)
                       GetM,         -- request for being modefied state
                       Inv,          -- Invalidate call
                       Inv_Ack,      -- Invalidate ack
                       PutM,        -- writeback request (w/ data)
                       PutS,        -- evict from share to I
                       Put_Ack,      -- response of PutM or PutS
                       Fwd_GetS, 	 -- Request & invalidate a share copy
                       Fwd_GetM,     -- Request & invalidate a modefied copy
                       Put_Ack_Back,
                       PutE,
                       ExData,
                       PutO,
                       AckCount,
                       AckCount_Back
                    };

  Message:
    Record
      mtype: MessageType;
      src: Node;
      vc: VCType;
      val: Value;
      ack: AckType;
    End;

  HomeState:
    Record
      state: enum { 
      --stable states
      H_Invalid, 
      H_Modified, 
      H_Shared, 
      H_Exclusive,
      H_Owned,
      --transient states during recall
      HT_S_D,
      HT_M_P,
      HT_S_P, 
      HT_I_P, 
      HT_E_P,
      HT_O_D,
      HT_O_P,
      HT_M_waitAckCount
      };
      owner: Node;	
      sharers: multiset [ProcCount] of Node;
      val: Value;
      ack: AckType;
    End;

  ProcState:
    Record
      state: enum { 
      P_Invalid, 
      P_Shared, 
      P_Modified, 
      P_Exclusive,
      P_Owned,
      PT_IS_D, 
      PT_IM_AD, 
      PT_IM_A, 
      PT_SM_AD, 
      PT_SM_A, 
      PT_MI_A, 
      PT_SI_A, 
      PT_II_A, 
      PT_EI_A,
      PT_OM_AC,
      PT_OM_A,
      PT_OI_A
      };
      val: Value;
      ack: AckType;
    End;

---------------------------------------------------------------------
-- Variables
---------------------------------------------------------------------
var
  HomeNode: HomeState;
  Procs: array [Proc] of ProcState;
  Net:   array [Node] of multiset [NetMax] of Message;
  InBox: array [Node] of array [VCType] of Message;
  msg_processed: boolean;
  LastWrite: Value;

---------------------------------------------------------------------
-- Procedures
---------------------------------------------------------------------
Procedure Send(
               mtype:MessageType;
               dst:Node;
               src:Node;
               vc:VCType;
               val:Value;
               ack:AckType;
               );
var msg:Message;
Begin
  Assert (MultiSetCount(i:Net[dst], true) < NetMax) "Too many messages";
  msg.mtype := mtype;
  msg.src   := src;
  msg.vc    := vc;
  msg.val   := val;
  msg.ack   := ack;
  MultiSetAdd(msg, Net[dst]);
End;

Procedure ErrorUnhandledMsg(msg:Message; n:Node);
Begin
  error "Unhandled message type!";
End;

Procedure ErrorUnhandledState();
Begin
  error "Unhandled state!";
End;

Procedure AddToSharersList(n:Node);
Begin
  if MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) = 0
  then
    MultiSetAdd(n, HomeNode.sharers);
  endif;
End;

Function IsSharer(n:Node) : Boolean;
Begin
  return MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) > 0
End;

Procedure RemoveFromSharersList(n:Node);
Begin
  MultiSetRemovePred(i:HomeNode.sharers, HomeNode.sharers[i] = n);
End;

Procedure RemoveAllSharersList();
for n:Node do
RemoveFromSharersList(n);
endfor;
End;



Procedure SendInvReqToSharers(rqst:Node);
Begin
 for n:Node do
  if(IsMember(n, Proc) & MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) != 0)
  then
   if n != rqst
    then
    Send(Inv, n, rqst, VC1, UNDEFINED, UNDEFINED); --put "Send Inv to "; --put n;--put "\n";
   endif;
  endif;
 endfor;
End;

Procedure print();
Begin
--put "---------------------------------\n";
--put HomeNode.state;
for n:Proc do
--put Procs[n].state;
endfor;
for n:Proc do
--put MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n);
--put " ";
endfor;
--put "\n";
End;

Procedure print2();
Begin
--put HomeNode.state;
for n:Proc do
--put Procs[n].state;
endfor;
for n:Proc do
--put MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n);
--put " ";
endfor;
--put "\n=================================\n";
End;


Procedure HomeReceive(msg:Message);
var cnt:-ProcCount..ProcCount; -- for counting sharers
Begin
--put "Home Receiving "; --put msg.mtype; --put " from "; --put msg.src; --put " on VC"; --put msg.vc;
--put "\n home --    "; --put HomeNode.state;
 cnt := MultiSetCount(i:HomeNode.sharers, true);--put cnt;
 msg_processed := true;

switch HomeNode.state


case H_Invalid:

    switch msg.mtype

    case GetS:
      HomeNode.state := H_Exclusive;
      Send(ExData, msg.src, HomeType, VC0, HomeNode.val, 0); --put "Send GetData to "; --put msg.src;--put " ack=0\n";
      HomeNode.owner := msg.src;
    case GetM:
      HomeNode.state := HT_M_waitAckCount;
      RemoveAllSharersList();
      HomeNode.owner := msg.src;
      Assert (!IsUndefined(HomeNode.val)) "homenode.val is undefined";
      Send(GetData, msg.src, HomeType, VC0, HomeNode.val, cnt); --put "Send GetData to "; --put msg.src;--put " ack="; --put cnt;--put "\n";
    case PutS:
      Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
      HomeNode.state := HT_I_P;
    case PutM:
      if(msg.src != HomeNode.owner)
      then
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_I_P;
      else
        ErrorUnhandledMsg(msg, HomeType);
      endif;
    case PutE:
      if(msg.src != HomeNode.owner)
      then
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_I_P;
        else
        ErrorUnhandledMsg(msg, HomeType);
      endif;
    case PutO:
      if(msg.src != HomeNode.owner)
      then
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_I_P;
      else
        ErrorUnhandledMsg(msg, HomeType);
      endif;

    else
    ErrorUnhandledMsg(msg, HomeType);
    endswitch;


case H_Shared:

    switch msg.mtype
    case GetS:
    Assert (!IsUndefined(HomeNode.val)) "homenode.val is undefined";
      Send(GetData, msg.src, HomeType, VC0, HomeNode.val, 0); --put "Send GetData to "; --put msg.src;--put " ack=0\n";
      AddToSharersList(msg.src);
    case GetM:
      HomeNode.owner := msg.src;
      if(IsSharer(msg.src))
      then
      Assert (!IsUndefined(HomeNode.val)) "homenode.val is undefined";
        Send(GetData, msg.src, HomeType, VC0, HomeNode.val, cnt-1); --put "Send GetData to "; --put msg.src;--put " ack="; --put cnt-1;--put "\n";
        HomeNode.state := HT_M_waitAckCount;
      else
      Assert (!IsUndefined(HomeNode.val)) "homenode.val is undefined";
      Send(GetData, msg.src, HomeType, VC0, HomeNode.val, cnt); --put "Send GetData to "; --put msg.src;--put " ack="; --put cnt;--put "\n";
        HomeNode.state := HT_M_waitAckCount;
      endif;
      SendInvReqToSharers(msg.src);
      RemoveFromSharersList(msg.src);
    case PutS:
      if(IsSharer(msg.src))
      then
        RemoveFromSharersList(msg.src);
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        if(MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = msg.src) = 1) --last in list
        then
            HomeNode.state := HT_I_P;
        else
            HomeNode.state := HT_S_P;
        endif;
      else
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        if(MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = msg.src) = 1) --last in list
        then
            HomeNode.state := HT_I_P;
        else
            HomeNode.state := HT_S_P;
        endif;
      endif;
    case PutM:
      if(msg.src != HomeNode.owner)
      then
        RemoveFromSharersList(msg.src);
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_S_P;
      else
        ErrorUnhandledMsg(msg, HomeType);
      endif;
    case PutE:
      if(msg.src != HomeNode.owner)
      then
        RemoveFromSharersList(msg.src);
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_S_P;
      else
        ErrorUnhandledMsg(msg, HomeType);
      endif;
    case PutO:
      if(msg.src != HomeNode.owner)
      then
        RemoveFromSharersList(msg.src);
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_S_P;
      else
        ErrorUnhandledMsg(msg, HomeType);
      endif;

    else
    ErrorUnhandledMsg(msg, HomeType);
    endswitch;


case H_Exclusive:
Assert (IsUndefined(HomeNode.owner) = false)
     "HomeNode has no owner, but line is Exclusive";
    switch msg.mtype
        case GetS:
        Assert (HomeNode.owner != msg.src) "owner = msg.src";
            Send(Fwd_GetS, HomeNode.owner, msg.src, VC1, UNDEFINED, UNDEFINED); --put "Send Fwd_GetS to "; --put HomeNode.owner;
            AddToSharersList(msg.src);                           --Add request to sharers
            --AddToSharersList(HomeNode.owner);
            RemoveFromSharersList(HomeNode.owner);               --Remove owner from sharers 
            --undefine HomeNode.owner;      
            HomeNode.state := HT_O_D;                            --change state to HT_S_D
        case GetM:
            Send(Fwd_GetM, HomeNode.owner, msg.src, VC1, UNDEFINED, 0); --put "Send Fwd_GetM to "; --put HomeNode.owner;
            HomeNode.owner := msg.src;
            HomeNode.state := HT_M_waitAckCount;
        case PutS:
            Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
            HomeNode.state := HT_E_P;
        case PutM:
            Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
            if(msg.src = HomeNode.owner)
            then
                Assert (!IsUnDefined(HomeNode.owner)) "owner undefined";
                HomeNode.state := HT_I_P;                       --change state to H_Invalid
                HomeNode.val := msg.val;                           --write data to memory
                LastWrite := HomeNode.val;
                --put "LastWrite changes to "; --put LastWrite; --put "\n";
                undefine HomeNode.owner;                           --undefine owner
                --RemoveAllSharersList();
            else
                HomeNode.state := HT_E_P;
            endif;
        case PutE:
            Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
            if(msg.src = HomeNode.owner)
            then
                Assert (!IsUnDefined(HomeNode.owner)) "owner undefined";
                HomeNode.state := HT_I_P;                       --change state to H_Invalid
                undefine HomeNode.owner;                           --undefine owner
                --RemoveAllSharersList();
            else
                HomeNode.state := HT_E_P;
            endif;
        case PutO:
            Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
            HomeNode.state := HT_E_P;
            --RemoveAllSharersList();
        else
            ErrorUnhandledMsg(msg, HomeType);
    endswitch;


case H_Modified:

    Assert (IsUndefined(HomeNode.owner) = false)
     "HomeNode has no owner, but line is Modified";
    switch msg.mtype
    case GetS:
    Assert (HomeNode.owner != msg.src) "owner = msg.src";
      Send(Fwd_GetS, HomeNode.owner, msg.src, VC1, UNDEFINED, UNDEFINED); --Send Fwd_GetS to owner
        --put "Send Fwd_GetS to "; --put HomeNode.owner;
      AddToSharersList(msg.src);                           --Add request to sharers
      RemoveFromSharersList(HomeNode.owner);               --Remove owner from sharers
      HomeNode.state := HT_O_D;                            --change state to HT_O_D
    case GetM:
      Send(Fwd_GetM, HomeNode.owner, msg.src, VC1, UNDEFINED, 0); --put "Send Fwd_GetM to "; --put HomeNode.owner;
      HomeNode.owner := msg.src;
      HomeNode.state := HT_M_waitAckCount;
      --RemoveAllSharersList();   --remove all, in case
    case PutS:
      Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_M_P;
        --RemoveAllSharersList();  --remove all, in case
    case PutM:
      Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
      --RemoveAllSharersList();
      if(msg.src = HomeNode.owner)
        then
            Assert (!IsUnDefined(HomeNode.owner)) "owner undefined";
            HomeNode.state := HT_I_P;                       --change state to H_Invalid
            HomeNode.val := msg.val;                           --write data to memory
            LastWrite := HomeNode.val;
            --put "LastWrite changes to "; --put LastWrite; --put "\n";
            undefine HomeNode.owner;                           --undefine owner
      else
            HomeNode.state := HT_M_P;
      endif;
    case PutE:
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_M_P;
        --RemoveAllSharersList();
    case PutO:
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_M_P;
        --RemoveAllSharersList();
    else
    ErrorUnhandledMsg(msg, HomeType);
    endswitch;


case H_Owned:
Assert (IsUndefined(HomeNode.owner) = false)
     "HomeNode has no owner, but line is Owned";
    switch msg.mtype
    case GetS:
    Assert (HomeNode.owner != msg.src) "owner = msg.src";
      Send(Fwd_GetS, HomeNode.owner, msg.src, VC1, UNDEFINED, UNDEFINED); --put "Send Fwd_GetS to "; --put HomeNode.owner;
      RemoveFromSharersList(HomeNode.owner);               --Remove owner from sharers
      AddToSharersList(msg.src);                           --Add request to sharers
      HomeNode.state := HT_O_D;                            --change state to HT_O_D
    case GetM:
      if(msg.src = HomeNode.owner) -- from owner
      then
        Send(AckCount, msg.src, HomeType, VC1, UNDEFINED, cnt);--put "Send AckCount to "; --put msg.src;--put " ack="; --put cnt;--put "\n";
        SendInvReqToSharers(msg.src);
        HomeNode.state := HT_M_waitAckCount;
       
        
      else --not from owner
        SendInvReqToSharers(msg.src);
        if(IsSharer(msg.src))
        then
        Assert(msg.src != HomeNode.owner) "msg.src = owner";
            Send(Fwd_GetM, HomeNode.owner, msg.src, VC1, UNDEFINED, cnt-1); --put "Send Fwd_GetM to "; --put HomeNode.owner;--put " ack="; --put cnt-1;--put "\n";
            HomeNode.owner := msg.src;
            --RemoveAllSharersList();
            HomeNode.state := HT_M_waitAckCount;
        else
        Assert(msg.src != HomeNode.owner) "msg.src = owner";
            Send(Fwd_GetM, HomeNode.owner, msg.src, VC1, UNDEFINED, cnt); --put "Send Fwd_GetM to "; --put HomeNode.owner;--put " ack="; --put cnt;--put "\n";
            HomeNode.owner := msg.src;
            --RemoveAllSharersList();
            HomeNode.state := HT_M_waitAckCount;
        endif;
      endif;
      
    case PutS:
        HomeNode.state := HT_O_P;
        RemoveFromSharersList(msg.src);
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
    case PutM:
        RemoveFromSharersList(msg.src);
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED);--put "Send Put_Ack to "; --put msg.src;--put "\n";
        if(msg.src = HomeNode.owner)
        then
            Assert (!IsUnDefined(HomeNode.owner)) "owner undefined";
            HomeNode.val := msg.val;                           --write data to memory
            LastWrite := HomeNode.val;
            --put "LastWrite changes to "; --put LastWrite; --put "\n";
            HomeNode.state := HT_S_P;                       --change state to HT_S_P
            undefine HomeNode.owner;                           --undefine owner
        else
            HomeNode.state := HT_O_P;
        endif;
    case PutO:
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED);--put "Send Put_Ack to "; --put msg.src;--put "\n";
        RemoveFromSharersList(msg.src);
        if(msg.src = HomeNode.owner)
        then
            Assert (!IsUnDefined(HomeNode.owner)) "owner undefined";            
            HomeNode.val := msg.val;                           --write data to memory
            LastWrite := HomeNode.val;
            --put "LastWrite changes to "; --put LastWrite; --put "\n";
            HomeNode.state := HT_S_P;                       --change state to HT_S_P
            undefine HomeNode.owner;                           --undefine owner
        else
            HomeNode.state := HT_O_P;
        endif;
    case PutE:
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED);--put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_S_P;                       --change state to HT_S_P
        undefine HomeNode.owner;
        RemoveFromSharersList(msg.src);
    else
    ErrorUnhandledMsg(msg, HomeType);
    endswitch;


case HT_S_D:

    switch msg.mtype
    case GetData:
      HomeNode.state := H_Shared;
      HomeNode.val := msg.val;
      LastWrite := HomeNode.val;
      --put "LastWrite changes to"; --put LastWrite; --put "\n";
    else
    msg_processed := false; --put "store in box\n";
    endswitch;


case HT_M_P:

    switch msg.mtype
    case Put_Ack_Back:
        HomeNode.state := H_Modified;
        RemoveAllSharersList();
    else
        msg_processed := false; --put "store in box\n";
    endswitch;


case HT_S_P:

    switch msg.mtype
    case Put_Ack_Back:
        HomeNode.state := H_Shared;
    else
        msg_processed := false; --put "store in box\n";
    endswitch;


case HT_I_P:

    switch msg.mtype
    case Put_Ack_Back:
        HomeNode.state := H_Invalid;
        RemoveAllSharersList();
    else
        msg_processed := false; --put "store in box\n";
    endswitch;


case HT_E_P:

    switch msg.mtype
    case Put_Ack_Back:
        HomeNode.state := H_Exclusive;
    else
        msg_processed := false; --put "store in box\n";
    endswitch;


case HT_O_D:
    switch msg.mtype
    case GetData:
        HomeNode.state := H_Owned;
    else
        msg_processed := false; --put "store in box\n";
    endswitch;


case HT_O_P:

    switch msg.mtype
    case Put_Ack_Back:
        HomeNode.state := H_Owned;
    else
        msg_processed := false; --put "store in box\n";
    endswitch;


case HT_M_waitAckCount:

    switch msg.mtype
    case AckCount_Back:
        HomeNode.state := H_Modified;
        undefine HomeNode.ack;
        RemoveAllSharersList();
    else
        msg_processed := false; --put "store in box\n";
    endswitch;
    
 endswitch;
--put HomeNode.val;
--put LastWrite; --put "\n";
--put HomeNode.owner;
--Assert (!IsSharer(HomeNode.owner)) "owner is in share list";
--put " changes to "; --put HomeNode.state;--put "\n";
End;











Procedure ProcReceive(msg:Message; p:Proc);
Begin
--put "Proc_"; --put p; --put " Receiving "; --put msg.mtype; --put " from "; --put msg.src; --put " on VC"; --put msg.vc; --put "\n";

msg_processed := true;
alias ps:Procs[p].state do
alias pv:Procs[p].val do
--put " Proc --    ";--put ps;
switch ps


case P_Invalid:

    msg_processed := false; --put "store in box\n";


case P_Shared:

    switch msg.mtype
    case Inv:
      Send(Inv_Ack, msg.src, p, VC0, UNDEFINED, UNDEFINED); --put "Send Inv_Ack to "; --put msg.src;--put "\n";
     -- Send(Inv_Ack, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send Inv_Ack to "; --put HomeType;--put "\n";
      ps := P_Invalid;
      undefine pv;
      undefine Procs[p].ack;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;


case P_Modified:

    switch msg.mtype
    case Fwd_GetS:
    Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType; --put "\n";
      ps := P_Owned;
    case Fwd_GetM:
    Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, 0); --put "Send GetData to "; --put msg.src;--put "EEEck = 0"; --put "\n";
    --  Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      ps := P_Invalid;
      undefine pv;
      undefine Procs[p].ack;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;


case P_Exclusive:

    switch msg.mtype
    case Fwd_GetS:
    Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put HomeType; --put "\n";
      ps := P_Owned;
    case Fwd_GetM:
    Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, 0); --put "Send GetData to "; --put msg.src;--put "DDDack = "; --put msg.ack; --put "\n";
    --  Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      ps := P_Invalid;
      undefine pv;
      undefine Procs[p].ack;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

    
case P_Owned:

    switch msg.mtype
      case Fwd_GetS:
      Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      case Fwd_GetM:
      Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, msg.ack); --put "Send GetData to "; --put msg.src;--put "CCCack = "; --put msg.ack; --put "\n";
   --   Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      ps := P_Invalid;
      undefine pv;
      undefine Procs[p].ack;
      else
        msg_processed := false; --put "store in box\n";
      endswitch;

case PT_IS_D:

    switch msg.mtype
    case Inv:
        msg_processed := false; --put "store in box\n";
    case GetData:
        pv := msg.val;
        LastWrite := pv;
        --put "LastWrite changes to "; --put LastWrite; --put "\n";
        --put Procs[p].ack;
    if(IsMember(msg.src, Proc))
    then
        ps := P_Shared;
        undefine Procs[p].ack;
    else
    if(!IsUndefined(msg.ack))
    then
      if(msg.ack = 0)
      then
        ps := P_Shared;
        undefine Procs[p].ack;
      else
        ErrorUnhandledMsg(msg, p);
      endif;
    else
      ErrorUnhandledMsg(msg,p);
    endif;
    endif;
    case Fwd_GetS:
      msg_processed := false; --put "store in box\n";
    case Fwd_GetM:
      msg_processed := false; --put "store in box\n";
    case ExData:
        if(IsMember(msg.src, Home))
        then
            ps := P_Exclusive;
            pv := msg.val;
            LastWrite := pv;
            --put "LastWrite changes to "; --put LastWrite; --put "\n";
            undefine Procs[p].ack;
        else
            ErrorUnhandledMsg(msg, p);
        endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;


case PT_IM_AD:

    switch msg.mtype
    case Fwd_GetM:
      msg_processed := false; --put "store in box\n";
    case Fwd_GetS:
      msg_processed := false; --put "store in box\n";
    case GetData:
      pv := msg.val;
      LastWrite := pv;
      --put "LastWrite changes to "; --put LastWrite; --put "\n";
      Assert (!IsUndefined(msg.ack)) "msg.ack is undefined";
      --put Procs[p].ack;
      if(!IsUndefined(msg.ack)) 
      then
        if(msg.ack = 0)
        then
            ps := P_Modified;
            undefine Procs[p].ack;
            Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;
        else
            if(IsUndefined(Procs[p].ack))
            then
                Procs[p].ack := msg.ack;
                ps := PT_IM_A;
            else
                if(Procs[p].ack + msg.ack = 0) -- Got all Inv_Ack, only need GetData to be Modified
                then
                    ps := P_Modified;
                    undefine Procs[p].ack;
                    Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;
                else
                    Procs[p].ack := Procs[p].ack + msg.ack;
                    ps := PT_IM_A;
                endif;
            endif;
        endif;
      else
        ErrorUnhandledMsg(msg,p);
      endif;
    case AckCount:
        Assert (!IsUndefined(msg.ack)) "msg.ack undefined";
        if(msg.ack = 0)
        then
            ps := P_Modified;
            undefine Procs[p].ack;
            Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;
        else
            ps := PT_OM_A;
            if(IsUndefined(Procs[p].ack))
            then
                Procs[p].ack := msg.ack;
            else
                if(Procs[p].ack + msg.ack = 0) -- Got all Inv_Ack, only need GetData to be Modified
                then
                    ps := P_Modified;
                    undefine Procs[p].ack;
                    Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;
                else
                    Procs[p].ack := Procs[p].ack + msg.ack;
                endif;
            endif;
        endif;
    case Inv_Ack:
        if(IsUndefined(Procs[p].ack))
        then
            Procs[p].ack := -1;
        else
            Procs[p].ack := Procs[p].ack - 1;
        endif;
            --put Procs[p].ack; --put "\n";

    else
      ErrorUnhandledMsg(msg,p);
    endswitch;


case PT_IM_A:

    switch msg.mtype
    case Fwd_GetM:
      msg_processed := false; --put "store in box\n";
    case Fwd_GetS:
      msg_processed := false; --put "store in box\n";
    case Inv_Ack:
    if(IsUndefined(Procs[p].ack))
    then
        Procs[p].ack := -1;
    else
        if(Procs[p].ack = 1)
        then
            ps := P_Modified;
            undefine Procs[p].ack;
            Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;
        else
            Procs[p].ack := Procs[p].ack - 1;
        endif;
    endif;
    --put Procs[p].ack; --put "\n";
    else
        ErrorUnhandledMsg(msg, p);
    endswitch;


case PT_SM_AD:

    switch msg.mtype
    case Fwd_GetM:
      msg_processed := false; --put "store in box\n";
    case Fwd_GetS:
      msg_processed := false; --put "store in box\n";
    case Inv:
      Send(Inv_Ack, msg.src, p, VC0, UNDEFINED, UNDEFINED); --put "Send Inv_Ack to "; --put msg.src;--put "\n";
    --  Send(Inv_Ack, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send Inv_Ack to "; --put HomeType;--put "\n";
      ps := PT_IM_AD;
    case GetData:
    pv := msg.val;
    LastWrite := pv;
    --put "LastWrite changes to "; --put LastWrite; --put "\n";
    --put Procs[p].ack;
    if(!IsUndefined(msg.ack))
    then
      if(msg.ack = 0)
      then
        ps := P_Modified;
        undefine Procs[p].ack;
        Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;
      else        
        if(IsUndefined(Procs[p].ack))
        then
          Procs[p].ack := msg.ack;
          ps := PT_SM_A;
        else
          if(Procs[p].ack + msg.ack = 0)
          then
            ps := P_Modified;
            undefine Procs[p].ack;
            Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;
          else
            Procs[p].ack := Procs[p].ack + msg.ack;
            ps := PT_SM_A;
          endif;
        endif;
        --put Procs[p].ack; --put "\n";
      endif;
    else
      ErrorUnhandledMsg(msg,p);
    endif;
    case Inv_Ack:
      if(IsUndefined(Procs[p].ack))
      then
        Procs[p].ack := -1;
        --put Procs[p].ack; --put "\n";
      else
        Procs[p].ack := Procs[p].ack - 1;
        --put Procs[p].ack; --put "\n";
      endif;
    else
      ErrorUnhandledMsg(msg,p);
    endswitch;


case PT_SM_A:

    switch msg.mtype
    case Fwd_GetS:
      msg_processed := false; --put "store in box\n";
    case Fwd_GetM:
      msg_processed := false; --put "store in box\n";
    case Inv_Ack:
    if(IsUndefined(Procs[p].ack))
    then
        Procs[p].ack := -1;
    else
        if(Procs[p].ack = 1)
        then
            ps := P_Modified;
            undefine Procs[p].ack;
            Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;
        else
            Procs[p].ack := Procs[p].ack - 1;
        endif;
    endif;
    --put Procs[p].ack; --put "\n";
    else
        ErrorUnhandledMsg(msg,p);
    endswitch;


case PT_MI_A:

    switch msg.mtype
    case Fwd_GetS:
    Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      ps := PT_OI_A;
    case Fwd_GetM:
    Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, 0); --put "Send GetData to "; --put msg.src;--put "FFFack = 0"; --put msg.ack; --put "\n";
    --  Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      ps := PT_II_A;
    case Put_Ack:
      ps := P_Invalid;
      undefine pv;
      undefine Procs[p].ack;
      Send(Put_Ack_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send Put_Ack_Back to "; --put HomeType;--put "\n";
    else
        ErrorUnhandledMsg(msg, p);
    endswitch;


case PT_EI_A:

    switch msg.mtype
    case Fwd_GetS:
    Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      ps := PT_OI_A;
    case Fwd_GetM:
    Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, 0); --put "Send GetData to "; --put msg.src;--put "BBBack = 0"; --put msg.ack; --put "\n";
    --  Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      ps := PT_II_A;
    case Put_Ack:
      ps := P_Invalid;
      undefine pv;
      undefine Procs[p].ack;
      Send(Put_Ack_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send Put_Ack_Back to "; --put HomeType;--put "\n";
    else
        ErrorUnhandledMsg(msg, p);
    endswitch;


case PT_OM_AC:

    switch msg.mtype
      case Fwd_GetS:
        Assert (!IsUndefined(pv)) "pv is undefined";
        Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
        Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      case Fwd_GetM:
        Assert (!IsUndefined(pv)) "pv is undefined";
        Send(GetData, msg.src, p, VC0, pv, msg.ack); --put "Send GetData to "; --put msg.src; --put "AAAck = "; --put msg.ack; --put "\n";
     --   Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
        ps := PT_IM_AD;
      case AckCount:
        Assert (!IsUndefined(msg.ack)) "msg.ack undefined";
        --put Procs[p].ack;
        if(msg.ack = 0)
        then
            ps := P_Modified;
            undefine Procs[p].ack;
            Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;--put "\n";
        else
            
            if(IsUndefined(Procs[p].ack))
            then
                Procs[p].ack := msg.ack;
                ps := PT_OM_A;
            else
                if(Procs[p].ack + msg.ack = 0) -- Got all Inv_Ack, only need GetData to be Modified
                then
                    ps := P_Modified;
                    undefine Procs[p].ack;
                    Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;--put "\n";
                else
                    Procs[p].ack := Procs[p].ack + msg.ack;
                    ps := PT_OM_A;
                endif;
            endif;
        endif;
      case GetData:
      pv := msg.val;
      LastWrite := pv;
      --put "LastWrite changes to "; --put LastWrite; --put "\n";
      Assert (!IsUndefined(msg.ack)) "msg.ack is undefined";
      --put Procs[p].ack;
      if(!IsUndefined(msg.ack)) 
      then
        if(msg.ack = 0)
        then
            ps := P_Modified;
            undefine Procs[p].ack;
            Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;
        else
            if(IsUndefined(Procs[p].ack))
            then
                Procs[p].ack := msg.ack;
                ps := PT_IM_A;
            else
                if(Procs[p].ack + msg.ack = 0) -- Got all Inv_Ack, only need GetData to be Modified
                then
                    ps := P_Modified;
                    undefine Procs[p].ack;
                    Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;
                else
                    Procs[p].ack := Procs[p].ack + msg.ack;
                    ps := PT_IM_A;
                endif;
            endif;
        endif;
      else
        ErrorUnhandledMsg(msg,p);
      endif;
      case Inv_Ack:
        if(IsUndefined(Procs[p].ack))
        then
            Procs[p].ack := -1;
        else
            Procs[p].ack := Procs[p].ack - 1;
        endif;
            --put Procs[p].ack; --put "\n";
      else
        --msg_processed := false; --put "store in box\n";
        ErrorUnhandledMsg(msg, p);
      endswitch;



case PT_OM_A:
 
    switch msg.mtype
    case Fwd_GetS:
    Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, msg.ack); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
    case Fwd_GetM:
      Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, msg.ack); --put "Send GetData to "; --put msg.src;--put "GGGack = "; --put msg.ack; --put "\n";
     -- Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";

    case Inv_Ack:
    if(IsUndefined(Procs[p].ack))
    then
        Procs[p].ack := -1;
    else
        if(Procs[p].ack = 1)
        then
            ps := P_Modified;
            undefine Procs[p].ack;
            Send(AckCount_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send AckCount_Back to "; --put HomeType;--put "\n";
        else
            Procs[p].ack := Procs[p].ack - 1;
        endif;
    endif;
    --put Procs[p].ack; --put "\n";
    else
        ErrorUnhandledMsg(msg,p);
    endswitch;

   
case PT_OI_A:

    switch msg.mtype
    case Fwd_GetS:
    Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
    case Fwd_GetM:
    Assert (!IsUndefined(pv)) "pv is undefined";
      Send(GetData, msg.src, p, VC0, pv, msg.ack); --put "Send GetData to "; --put msg.src;--put "AAAck = "; --put msg.ack; --put "\n";
    --  Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      --put "AAA "; --put msg.ack;
      ps := PT_II_A;
    case Put_Ack:
      ps := P_Invalid;
      undefine pv;
      undefine Procs[p].ack;
      Send(Put_Ack_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send Put_Ack_Back to "; --put HomeType;--put "\n";
    else
        ErrorUnhandledMsg(msg, p);
    endswitch;


case PT_SI_A:

    switch msg.mtype
    case Inv:
      Send(Inv_Ack, msg.src, p, VC0, UNDEFINED, UNDEFINED); --put "Send Inv_Ack to "; --put msg.src;--put "\n";
  --    Send(Inv_Ack, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send Inv_Ack to "; --put HomeType;--put "\n";
      ps := PT_II_A;
    case Put_Ack:
      ps := P_Invalid;
      undefine pv;
        undefine Procs[p].ack;
        Send(Put_Ack_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send Put_Ack_Back to "; --put HomeType;--put "\n";
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

case PT_II_A:
    switch msg.mtype
    case Put_Ack:
      ps := P_Invalid;
      undefine pv;
        undefine Procs[p].ack;
        Send(Put_Ack_Back, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send Put_Ack_Back to "; --put HomeType;--put "\n";
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  else
    ErrorUnhandledState();
 endswitch;
--put "msg.ack = "; --put msg.ack; --put "\n";
--put LastWrite; --put "\n";
--put "pv = "; --put pv; --put "\n";
--put HomeNode.val;
--put HomeNode.owner;
--put " changes to ";--put ps; --put "\n";
 endalias;
 endalias;
End;

----------------------------------------------------------------------
-- Rules
----------------------------------------------------------------------

-- Processor actions (affection coherency)
ruleset n:Proc Do
  alias p:Procs[n] Do

    ruleset v:Value Do
    rule "store new value when P_Modified"
     (p.state = P_Modified)
      ==>
        p.val := v;
        LastWrite := v; --put n; --put " write "; --put p.val; --put "\n";
        --put "LastWrite changes to "; --put LastWrite; --put "\n";
        --put HomeNode.val;
        --put HomeNode.owner;
        print2();
    endrule;


    rule "store new value when P_Shared"
     (p.state = P_Shared)
     ==>
        print(); --put " write \n";
        Send(GetM, HomeType, n, VC2, UNDEFINED, UNDEFINED);--put n; --put "Send GetM to Home\n";
        p.state := PT_SM_AD;
        --put HomeNode.val;
        --put HomeNode.owner; 
        print2();
    endrule;


    rule "store new value when P_Invalid"
     (p.state = P_Invalid)
     ==>
        print(); --put n; --put " write\n";
        Send(GetM, HomeType, n, VC2, UNDEFINED, UNDEFINED); --put "Send GetM to Home\n";
        p.state := PT_IM_AD;
        --put HomeNode.val;
        --put HomeNode.owner; 
        print2();
    endrule;

                    
    rule "store new value when P_Exclusive"
    (p.state = P_Exclusive)
    ==>
        print(); --put n; --put "write\n";
        p.state := P_Modified;
        --put HomeNode.val;
        --put HomeNode.owner; 
        print2();
    endrule;
 
    
    rule "store new value when P_Owned"
    (p.state = P_Owned)
    ==>
        print(); --put n; --put "write\n";
        Send(GetM, HomeType, n, VC2, UNDEFINED, UNDEFINED); --put "Send GetM to Home\n";
        p.state := PT_OM_AC;
        --put HomeNode.val;
        --put HomeNode.owner; 
        print2();
    endrule;
    
    endruleset;


  rule "read request when P_Invalid"
    (p.state = P_Invalid)
    ==>
        print();--put n; --put " read\n";
        Send(GetS, HomeType, n, VC2, UNDEFINED, UNDEFINED); --put "Send GetS to Home\n";
        p.state := PT_IS_D;
        --put HomeNode.val;
        --put HomeNode.owner; 
        print2();
    endrule;


  rule "writeback when P_Modified"
  (p.state = P_Modified)
    ==>
        print();--put n; --put " writeback\n";
        Send(PutM, HomeType, n, VC2, p.val, UNDEFINED);--put "Send PutM to Home\n";
        p.state := PT_MI_A;
        --put HomeNode.val;
        --put HomeNode.owner; 
        print2();
    endrule;


  rule "writeback when P_Shared"
  (p.state = P_Shared)
    ==>
        print(); --put n; --put " writeback\n";
        Send(PutS, HomeType, n, VC2, UNDEFINED, UNDEFINED); --put "Send PutS to Home\n";
        p.state := PT_SI_A;
        print2();
    endrule;
  
                   
  rule "writeback when P_Exclusive"
  (p.state = P_Exclusive)
  ==>
        print(); --put n; --put " writeback\n";
        Send(PutE, HomeType, n, VC2, UNDEFINED, UNDEFINED); --put "Send PutE to Home\n";
        p.state := PT_EI_A;
        print2();
    endrule;
 
   
  rule "writeback when P_Owned"
  (p.state = P_Owned)
  ==>
        print();--put n; --put " writeback\n";
        Send(PutO, HomeType, n, VC2, p.val, UNDEFINED); --put "Send PutO to Home\n";
        p.state := PT_OI_A;
        print2();
    endrule;

                    

  endalias;
endruleset;


-- Message delivery rules
ruleset n:Node do
 choose midx:Net[n] do
 alias chan:Net[n] do
 alias msg:chan[midx] do
 alias box:InBox[n] do

  rule "receive-net"
    (isundefined(box[msg.vc].mtype))
    ==>
print();
    if IsMember(n, Home)
    then
     HomeReceive(msg);
    else
     ProcReceive(msg, n);
    endif;
print2();
    if !msg_processed
    then
    box[msg.vc] := msg;
    endif;

    MultiSetRemove(midx, chan);
  endrule;

 endalias;
 endalias;
 endalias;
 endchoose;

  ruleset vc:VCType do
  rule "receive-blocked-vc"
    (! isundefined(InBox[n][vc].mtype))
    ==>
print();
    if IsMember(n, Home)
    then
     HomeReceive(InBox[n][vc]);
    else
     ProcReceive(InBox[n][vc], n);
    endif;

print2();
    if msg_processed -- Message has been handled, forget it
    then
    undefine InBox[n][vc];
    endif;

    endrule;
  endruleset;
endruleset;


----------------------------------------------------------------------
-- Startstate
----------------------------------------------------------------------
startstate

for v:Value do
-- home node initialization
HomeNode.state := H_Invalid;
undefine HomeNode.owner;
undefine HomeNode.ack;
HomeNode.val := v;
    -- initialize sharelist
    for n:Node do
    RemoveFromSharersList(n);
    endfor;
endfor;
LastWrite := HomeNode.val;
--put "LastWrite changes to "; --put LastWrite; --put "\n";

-- processor initialization
for i:Proc do
    Procs[i].state := P_Invalid;
    undefine Procs[i].val;
    undefine Procs[i].ack;
endfor;

-- network initialization
undefine Net;

endstartstate;

----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------

invariant "Invalid implies empty owner"
  HomeNode.state = H_Invalid
    ->
    IsUndefined(HomeNode.owner);
    
invariant "Shared implies empty owner"
  HomeNode.state = H_Shared
    ->
    IsUndefined(HomeNode.owner);

invariant "value in memory matches value of last write, when shared "
    HomeNode.state = H_Shared
    ->
    HomeNode.val = LastWrite;

invariant "value in memory matches value of last write, when invalid"
    HomeNode.state = H_Invalid
    ->
    HomeNode.val = LastWrite;
    
invariant "value in memory matches value of last write, when owned"
    HomeNode.state = H_Owned
    ->
    HomeNode.val = LastWrite;

invariant "values in modified state match last write"
    Forall n : Proc Do
    Procs[n].state = P_Modified
    ->
    Procs[n].val = LastWrite --LastWrite is updated whenever a new value is created
    end;
    
invariant "values in exclusive state match last write"
    Forall n : Proc Do
    Procs[n].state = P_Exclusive
    ->
    Procs[n].val = LastWrite --LastWrite is updated whenever a new value is created
    end;
    
invariant "values in owned state match last write"
    Forall n : Proc Do
    Procs[n].state = P_Owned
    ->
    Procs[n].val = LastWrite --LastWrite is updated whenever a new value is created
    end;

invariant "value is undefined while invalid"
    Forall n : Proc Do
    Procs[n].state = P_Invalid
    ->
    IsUndefined(Procs[n].val)
    end;

invariant "modified implies empty sharers list"
    HomeNode.state = H_Modified
    ->
     MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "Invalid implies empty sharer list"
    HomeNode.state = H_Invalid
    ->
    MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "Exclusive implies empty sharer list"
    HomeNode.state = H_Exclusive
    ->
    MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "values in shared state match memory"
Forall n: Proc Do
    HomeNode.state = H_Shared & Procs[n].state = P_Shared
    ->
    HomeNode.val = Procs[n].val
end;

invariant "values in exlusive state match memory"
Forall n: Proc Do
    HomeNode.state = H_Exclusive & Procs[n].state = P_Exclusive
    ->
    HomeNode.val = Procs[n].val
end;

invariant "values in owned state match memory"
Forall n: Proc Do
    HomeNode.state = H_Owned & Procs[n].state = P_Owned
    ->
    HomeNode.val = Procs[n].val
end;
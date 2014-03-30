
-- MESI 3-hop MSI protocol

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
                       ExData
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
      state: enum { H_Invalid, H_Modified, H_Shared, H_Exclusive,--stable states
    HT_S_D, HT_M_D, HT_M_P, HT_M_A, HT_S_P, HT_I_P, HT_E_P};--transient states during recall
      owner: Node;	
      sharers: multiset [ProcCount] of Node;
      val: Value;
      ack: AckType;
    End;

  ProcState:
    Record
      state: enum { P_Invalid, P_Shared, P_Modified, P_Exclusive,
                  PT_IS_D, PT_IM_AD, PT_IM_A, PT_SM_AD, PT_SM_A, PT_MI_A, PT_SI_A, PT_II_A, PT_EI_A
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
var cnt:0..ProcCount; -- for counting sharers
Begin
--put "Home Receiving "; --put msg.mtype; --put " from "; --put msg.src; --put " on VC"; --put msg.vc;
--put "\n home --    "; --put HomeNode.state;
 cnt := MultiSetCount(i:HomeNode.sharers, true);
 msg_processed := true;

switch HomeNode.state


case H_Invalid:

    switch msg.mtype

    case GetS:
      HomeNode.state := H_Exclusive;
      Send(ExData, msg.src, HomeType, VC0, HomeNode.val, 0); --put "Send GetData to "; --put msg.src;--put " ack=0\n";
      HomeNode.owner := msg.src;

    case GetM:
      HomeNode.state := H_Modified;
      RemoveAllSharersList();
      HomeNode.owner := msg.src;
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

    else
    ErrorUnhandledMsg(msg, HomeType);
    endswitch;


case H_Shared:

    switch msg.mtype
    case GetS:
      Send(GetData, msg.src, HomeType, VC0, HomeNode.val, 0); --put "Send GetData to "; --put msg.src;--put " ack=0\n";
      AddToSharersList(msg.src);
    case GetM:
      HomeNode.owner := msg.src;
      if(IsSharer(msg.src))
      then
        Send(GetData, msg.src, HomeType, VC0, HomeNode.val, cnt-1); --put "Send GetData to "; --put msg.src;--put " ack="; --put cnt-1;--put "\n";
        if(cnt = 1)
        then
            HomeNode.state := H_Modified;
            RemoveAllSharersList();
        else
            HomeNode.state := HT_M_A;
        endif;
      else
      Send(GetData, msg.src, HomeType, VC0, HomeNode.val, cnt); --put "Send GetData to "; --put msg.src;--put " ack="; --put cnt;--put "\n";
        if(cnt = 0)
        then
            HomeNode.state := H_Modified;
            RemoveAllSharersList();
        else
            HomeNode.state := HT_M_A;
        endif;
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

    else
    ErrorUnhandledMsg(msg, HomeType);
    endswitch;


case H_Exclusive:

    switch msg.mtype
        case GetS:
            Send(Fwd_GetS, HomeNode.owner, msg.src, VC1, UNDEFINED, UNDEFINED); --put "Send Fwd_GetS to "; --put HomeNode.owner;
            AddToSharersList(msg.src);                           --Add request to sharers
            AddToSharersList(HomeNode.owner);                    --Add owner to sharers
            undefine HomeNode.owner;                             --undefine owner
            HomeNode.state := HT_S_D;                            --change state to HT_S_D
        case GetM:
            Send(Fwd_GetM, HomeNode.owner, msg.src, VC1, UNDEFINED, UNDEFINED); --put "Send Fwd_GetM to "; --put HomeNode.owner;
            HomeNode.owner := msg.src;
            HomeNode.state := HT_M_D;
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
        else
            ErrorUnhandledMsg(msg, HomeType);
    endswitch;


case H_Modified:

    Assert (IsUndefined(HomeNode.owner) = false)
     "HomeNode has no owner, but line is Modified";
    switch msg.mtype
    case GetS:
      Send(Fwd_GetS, HomeNode.owner, msg.src, VC1, UNDEFINED, UNDEFINED); --Send Fwd_GetS to owner
        --put "Send Fwd_GetS to "; --put HomeNode.owner;
      AddToSharersList(msg.src);                           --Add request to sharers
      AddToSharersList(HomeNode.owner);                    --Add owner to sharers
      undefine HomeNode.owner;                             --undefine owner
      HomeNode.state := HT_S_D;                            --change state to HT_S_D
    case GetM:
      Send(Fwd_GetM, HomeNode.owner, msg.src, VC1, UNDEFINED, UNDEFINED); --put "Send Fwd_GetM to "; --put HomeNode.owner;
      HomeNode.owner := msg.src;
        HomeNode.state := HT_M_D;
    case PutS:
      Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_M_P;
    case PutM:
      Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
      if(msg.src = HomeNode.owner)
        then
            Assert (!IsUnDefined(HomeNode.owner)) "owner undefined";
            HomeNode.state := HT_I_P;                       --change state to H_Invalid
            HomeNode.val := msg.val;                           --write data to memory
            LastWrite := HomeNode.val;
            undefine HomeNode.owner;                           --undefine owner
            --RemoveAllSharersList();
      else
            HomeNode.state := HT_M_P;
      endif;
    case PutE:
        Send(Put_Ack, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); --put "Send Put_Ack to "; --put msg.src;--put "\n";
        HomeNode.state := HT_M_P;
    else
    ErrorUnhandledMsg(msg, HomeType);
    endswitch;


case HT_S_D:

    switch msg.mtype
    case GetData:
      HomeNode.state := H_Shared;
      HomeNode.val := msg.val;
      LastWrite := HomeNode.val;
    else
    msg_processed := false; --put "store in box\n";
    endswitch;


case HT_M_D:

    switch msg.mtype
    case GetData:
        HomeNode.state := H_Modified;
        RemoveAllSharersList();
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


case HT_M_A:

    switch msg.mtype
    case Inv_Ack:
        if(IsUndefined(HomeNode.ack))
        then
            HomeNode.ack := 1;
        else
            HomeNode.ack := HomeNode.ack + 1;
        endif;
        --put HomeNode.ack;
        --put cnt;
        if(HomeNode.ack = cnt)
        then
            HomeNode.state := H_Modified;
            undefine HomeNode.ack;
            RemoveAllSharersList();
        endif;
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

 endswitch;
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
      Send(Inv_Ack, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send Inv_Ack to "; --put HomeType;--put "\n";
      ps := P_Invalid;
      undefine pv;
      undefine Procs[p].ack;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;


case P_Modified:

    switch msg.mtype
    case Fwd_GetS:
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put HomeType; --put "\n";
      ps := P_Shared;
    case Fwd_GetM:
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      ps := P_Invalid;
      undefine pv;
      undefine Procs[p].ack;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;


case P_Exclusive:

    switch msg.mtype
    case Fwd_GetS:
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put HomeType; --put "\n";
      ps := P_Shared;
    case Fwd_GetM:
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      ps := P_Invalid;
      undefine pv;
      undefine Procs[p].ack;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

case PT_IS_D:

    switch msg.mtype
    case Inv:
        msg_processed := false; --put "store in box\n";
    case GetData:
        pv := msg.val;
        LastWrite := pv;
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
      if(IsMember(msg.src, Proc))
      then
        ps := P_Modified;
        undefine Procs[p].ack;
      else
      if(!IsUndefined(msg.ack))
      then
        if(msg.ack = 0)
        then
            ps := P_Modified;
            undefine Procs[p].ack;
        else
            ps := PT_IM_A;
            if(IsUndefined(Procs[p].ack))
            then
                Procs[p].ack := msg.ack;
            else
                if(Procs[p].ack + msg.ack = 0) -- Got all Inv_Ack, only need GetData to be Modified
                then
                    ps := P_Modified;
                    undefine Procs[p].ack;
                else
                    Procs[p].ack := Procs[p].ack + msg.ack;
                endif;
            endif;
        endif;
      else
        ErrorUnhandledMsg(msg,p);
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
      Send(Inv_Ack, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send Inv_Ack to "; --put HomeType;--put "\n";
      ps := PT_IM_AD;
    case GetData:
    pv := msg.val;
    LastWrite := pv;
    if(IsMember(msg.src, Proc))
    then
      ps := P_Modified;
      undefine Procs[p].ack;
    else
    if(!IsUndefined(msg.ack))
    then
      if(msg.ack = 0)
      then
        ps := P_Modified;
        undefine Procs[p].ack;
      else
        ps := PT_SM_A;
        if(IsUndefined(Procs[p].ack))
        then
          Procs[p].ack := msg.ack;
        else
          if(Procs[p].ack + msg.ack = 0)
          then
            ps := P_Modified;
            undefine Procs[p].ack;
          else
            Procs[p].ack := Procs[p].ack + msg.ack;
          endif;
        endif;
        --put Procs[p].ack; --put "\n";
      endif;
    else
      ErrorUnhandledMsg(msg,p);
    endif;
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
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      ps := PT_SI_A;
    case Fwd_GetM:
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
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
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
      ps := PT_SI_A;
    case Fwd_GetM:
      Send(GetData, msg.src, p, VC0, pv, UNDEFINED); --put "Send GetData to "; --put msg.src;--put "\n";
      Send(GetData, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send GetData to "; --put HomeType;--put "\n";
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
      Send(Inv_Ack, HomeType, p, VC0, UNDEFINED, UNDEFINED); --put "Send Inv_Ack to "; --put HomeType;--put "\n";
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
        print2();
    endrule;


    rule "store new value when P_Shared"
     (p.state = P_Shared)
     ==>
        print(); --put " write \n";
        Send(GetM, HomeType, n, VC2, UNDEFINED, UNDEFINED);--put n; --put "Send GetM to Home\n";
        p.state := PT_SM_AD;
        print2();
    endrule;


    rule "store new value when P_Invalid"
     (p.state = P_Invalid)
     ==>
        print(); --put n; --put " write\n";
        Send(GetM, HomeType, n, VC2, UNDEFINED, UNDEFINED); --put "Send GetM to Home\n";
        p.state := PT_IM_AD;
        print2();
    endrule;

                    
    rule "store new value when P_Exclusive"
    (p.state = P_Exclusive)
    ==>
        print(); --put n; --put "write\n";
        p.state := P_Modified;
        print2();
    endrule;
    
    endruleset;


  rule "read request when P_Invalid"
    (p.state = P_Invalid)
    ==>
        print();--put n; --put " read\n";
        Send(GetS, HomeType, n, VC2, UNDEFINED, UNDEFINED); --put "Send GetS to Home\n";
        p.state := PT_IS_D;
        print2();
    endrule;


  rule "writeback when P_Modified"
  (p.state = P_Modified)
    ==>
        print();--put n; --put " writeback\n";
        Send(PutM, HomeType, n, VC2, p.val, UNDEFINED);--put "Send PutM to Home\n";
        p.state := PT_MI_A;
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
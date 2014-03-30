/******************************
  Program "msi.m" compiled by "Murphi Release 3.1"

  Murphi Last Modefied Date: "Jan 29 1999"
  Murphi Last Compiled date: "Mar 12 2014"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Murphi Release 3.1"
#define MURPHI_DATE "Jan 29 1999"
#define PROTOCOL_NAME "msi"
#define BITS_IN_WORLD 1640
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_Proc: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Proc& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Proc& val)
    {
      if (val.defined())
        return ( s << mu_1_Proc::values[ int(val) - 1 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Proc (char *name, int os): mu__byte(1, 2, 2, name, os) {};
  mu_1_Proc (void): mu__byte(1, 2, 2) {};
  mu_1_Proc (int val): mu__byte(1, 2, 2, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Proc& a, mu_1_Proc& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_Proc::values[] =
  { "Proc_1","Proc_2",NULL };

/*** end scalarset declaration ***/
mu_1_Proc mu_1_Proc_undefined_var;

class mu_1_Value: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Value& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Value& val)
    {
      if (val.defined())
        return ( s << mu_1_Value::values[ int(val) - 3 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Value (char *name, int os): mu__byte(3, 3, 1, name, os) {};
  mu_1_Value (void): mu__byte(3, 3, 1) {};
  mu_1_Value (int val): mu__byte(3, 3, 1, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -3]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 3] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Value& a, mu_1_Value& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_Value::values[] =
  { "Value_1",NULL };

/*** end scalarset declaration ***/
mu_1_Value mu_1_Value_undefined_var;

class mu_1_Home: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Home& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Home& val)
  {
    if (val.defined())
      return ( s << mu_1_Home::values[ int(val) - 4] );
    else return ( s << "Undefined" );
  };

  mu_1_Home (char *name, int os): mu__byte(4, 4, 1, name, os) {};
  mu_1_Home (void): mu__byte(4, 4, 1) {};
  mu_1_Home (int val): mu__byte(4, 4, 1, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -4]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -4] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_Home::values[] = {"HomeType",NULL };

/*** end of enum declaration ***/
mu_1_Home mu_1_Home_undefined_var;

class mu_1_Node: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Node& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Node& val)
    {
      if (val.defined())
        return ( s << mu_1_Node::values[ val.indexvalue() ] );
      else
        return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_Node (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_Node (void): mu__byte(0, 2, 2) {};
  mu_1_Node (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
    { operator=(val); };
  int indexvalue()
  {
    if ((value() >= 4) && (value() <= 4)) return (value() - 4);
    if ((value() >= 1) && (value() <= 2)) return (value() - 0);
  };
  inline int unionassign(int val)
  {
    if (val >= 0 && val <= 0) return value(val+4);
    if (val >= 1 && val <= 2) return value(val+0);
  };
  char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_Node& a, mu_1_Node& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
char *mu_1_Node::values[] = {"HomeType","Proc_1","Proc_2",NULL };

/*** end union declaration ***/
mu_1_Node mu_1_Node_undefined_var;

class mu_1_VCType: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_VCType& val) { return mu__byte::operator=((int) val); };
  mu_1_VCType (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_VCType (void): mu__byte(0, 2, 2) {};
  mu_1_VCType (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_VCType mu_1_VCType_undefined_var;

class mu_1_AckType: public mu__long
{
 public:
  inline int operator=(int val) { return mu__long::operator=(val); };
  inline int operator=(const mu_1_AckType& val) { return mu__long::operator=((int) val); };
  mu_1_AckType (char *name, int os): mu__long(-2, 2, 3, name, os) {};
  mu_1_AckType (void): mu__long(-2, 2, 3) {};
  mu_1_AckType (int val): mu__long(-2, 2, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_AckType mu_1_AckType_undefined_var;

class mu_1_MessageType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MessageType& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MessageType& val)
  {
    if (val.defined())
      return ( s << mu_1_MessageType::values[ int(val) - 5] );
    else return ( s << "Undefined" );
  };

  mu_1_MessageType (char *name, int os): mu__byte(5, 16, 4, name, os) {};
  mu_1_MessageType (void): mu__byte(5, 16, 4) {};
  mu_1_MessageType (int val): mu__byte(5, 16, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -5]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -5] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_MessageType::values[] = {"GetS","GetData","GetM","Inv","Inv_Ack","PutM","PutS","Put_Ack","Fwd_GetS","Fwd_GetM","Put_Ack_Back","GetData_Ack",NULL };

/*** end of enum declaration ***/
mu_1_MessageType mu_1_MessageType_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_MessageType mu_mtype;
  mu_1_Node mu_src;
  mu_1_VCType mu_vc;
  mu_1_Value mu_val;
  mu_1_AckType mu_ack;
  mu_1_Message ( char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = CompareWeight(a.mu_vc, b.mu_vc);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = CompareWeight(a.mu_ack, b.mu_ack);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = Compare(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = Compare(a.mu_vc, b.mu_vc);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = Compare(a.mu_ack, b.mu_ack);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_mtype.MultisetSort();
    mu_src.MultisetSort();
    mu_vc.MultisetSort();
    mu_val.MultisetSort();
    mu_ack.MultisetSort();
  }
  void print_statistic()
  {
    mu_mtype.print_statistic();
    mu_src.print_statistic();
    mu_vc.print_statistic();
    mu_val.print_statistic();
    mu_ack.print_statistic();
  }
  void clear() {
    mu_mtype.clear();
    mu_src.clear();
    mu_vc.clear();
    mu_val.clear();
    mu_ack.clear();
 };
  void undefine() {
    mu_mtype.undefine();
    mu_src.undefine();
    mu_vc.undefine();
    mu_val.undefine();
    mu_ack.undefine();
 };
  void reset() {
    mu_mtype.reset();
    mu_src.reset();
    mu_vc.reset();
    mu_val.reset();
    mu_ack.reset();
 };
  void print() {
    mu_mtype.print();
    mu_src.print();
    mu_vc.print();
    mu_val.print();
    mu_ack.print();
  };
  void print_diff(state *prevstate) {
    mu_mtype.print_diff(prevstate);
    mu_src.print_diff(prevstate);
    mu_vc.print_diff(prevstate);
    mu_val.print_diff(prevstate);
    mu_ack.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_mtype.to_state(thestate);
    mu_src.to_state(thestate);
    mu_vc.to_state(thestate);
    mu_val.to_state(thestate);
    mu_ack.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_mtype.value(from.mu_mtype.value());
    mu_src.value(from.mu_src.value());
    mu_vc.value(from.mu_vc.value());
    mu_val.value(from.mu_val.value());
    mu_ack.value(from.mu_ack.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(char *n, int os)
{
  name = n;
  mu_mtype.set_self_2(name, ".mtype", os + 0 );
  mu_src.set_self_2(name, ".src", os + 8 );
  mu_vc.set_self_2(name, ".vc", os + 16 );
  mu_val.set_self_2(name, ".val", os + 24 );
  mu_ack.set_self_2(name, ".ack", os + 32 );
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_0& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_0& val)
  {
    if (val.defined())
      return ( s << mu_1__type_0::values[ int(val) - 17] );
    else return ( s << "Undefined" );
  };

  mu_1__type_0 (char *name, int os): mu__byte(17, 27, 4, name, os) {};
  mu_1__type_0 (void): mu__byte(17, 27, 4) {};
  mu_1__type_0 (int val): mu__byte(17, 27, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -17]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -17] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_0::values[] = {"H_Invalid","H_Modified","H_Shared","HT_S_D","HT_M_D","HT_M_P","HT_M_A","HT_S_P","HT_I_P","HT_M_ADa","HT_M_Da",NULL };

/*** end of enum declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_1_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_1_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_1_id () : mu__byte(0,1,0) {};
  mu_1__type_1_id (int val) : mu__byte(0,1,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_1
{
 public:
  mu_1_Node array[ 2 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 2 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_1 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_1 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_1 ();
  mu_1_Node& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 1) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 2; i++)
    {
        array[i].value(from.array[i].value());
        valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 2; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 2; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 2; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 2; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 2; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_1_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 2; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 2; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Node &element)
  {
    update_size();
    if (current_size >= 2) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 2; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_1_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Node temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 2; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 2; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 2; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_1::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_1::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_1::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 2; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 8 + os);
  k = os + i * 8;
  for(i = 0; i < 2; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_1::~mu_1__type_1()
{
}
/*** end multiset declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1_HomeState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_0 mu_state;
  mu_1_Node mu_owner;
  mu_1__type_1 mu_sharers;
  mu_1_Value mu_val;
  mu_1_AckType mu_ack;
  mu_1_HomeState ( char *n, int os ) { set_self(n,os); };
  mu_1_HomeState ( void ) {};

  virtual ~mu_1_HomeState(); 
friend int CompareWeight(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = CompareWeight(a.mu_sharers, b.mu_sharers);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = CompareWeight(a.mu_ack, b.mu_ack);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = Compare(a.mu_sharers, b.mu_sharers);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = Compare(a.mu_ack, b.mu_ack);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_owner.MultisetSort();
    mu_sharers.MultisetSort();
    mu_val.MultisetSort();
    mu_ack.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_owner.print_statistic();
    mu_sharers.print_statistic();
    mu_val.print_statistic();
    mu_ack.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_owner.clear();
    mu_sharers.clear();
    mu_val.clear();
    mu_ack.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_owner.undefine();
    mu_sharers.undefine();
    mu_val.undefine();
    mu_ack.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_owner.reset();
    mu_sharers.reset();
    mu_val.reset();
    mu_ack.reset();
 };
  void print() {
    mu_state.print();
    mu_owner.print();
    mu_sharers.print();
    mu_val.print();
    mu_ack.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_owner.print_diff(prevstate);
    mu_sharers.print_diff(prevstate);
    mu_val.print_diff(prevstate);
    mu_ack.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_owner.to_state(thestate);
    mu_sharers.to_state(thestate);
    mu_val.to_state(thestate);
    mu_ack.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_HomeState& operator= (const mu_1_HomeState& from) {
    mu_state.value(from.mu_state.value());
    mu_owner.value(from.mu_owner.value());
    mu_sharers = from.mu_sharers;
    mu_val.value(from.mu_val.value());
    mu_ack.value(from.mu_ack.value());
    return *this;
  };
};

  void mu_1_HomeState::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_HomeState::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_HomeState::set_self(char *n, int os)
{
  name = n;
  mu_state.set_self_2(name, ".state", os + 0 );
  mu_owner.set_self_2(name, ".owner", os + 8 );
  mu_sharers.set_self_2(name, ".sharers", os + 16 );
  mu_val.set_self_2(name, ".val", os + 48 );
  mu_ack.set_self_2(name, ".ack", os + 56 );
}

mu_1_HomeState::~mu_1_HomeState()
{
}

/*** end record declaration ***/
mu_1_HomeState mu_1_HomeState_undefined_var;

class mu_1__type_2: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_2& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_2& val)
  {
    if (val.defined())
      return ( s << mu_1__type_2::values[ int(val) - 28] );
    else return ( s << "Undefined" );
  };

  mu_1__type_2 (char *name, int os): mu__byte(28, 38, 4, name, os) {};
  mu_1__type_2 (void): mu__byte(28, 38, 4) {};
  mu_1__type_2 (int val): mu__byte(28, 38, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -28]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -28] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_2::values[] = {"P_Invalid","P_Shared","P_Modified","PT_IS_D","PT_IM_AD","PT_IM_A","PT_SM_AD","PT_SM_A","PT_MI_A","PT_SI_A","PT_II_A",NULL };

/*** end of enum declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1_ProcState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_2 mu_state;
  mu_1_Value mu_val;
  mu_1_AckType mu_ack;
  mu_1_ProcState ( char *n, int os ) { set_self(n,os); };
  mu_1_ProcState ( void ) {};

  virtual ~mu_1_ProcState(); 
friend int CompareWeight(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = CompareWeight(a.mu_ack, b.mu_ack);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = Compare(a.mu_ack, b.mu_ack);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_val.MultisetSort();
    mu_ack.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_val.print_statistic();
    mu_ack.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_val.clear();
    mu_ack.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_val.undefine();
    mu_ack.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_val.reset();
    mu_ack.reset();
 };
  void print() {
    mu_state.print();
    mu_val.print();
    mu_ack.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_val.print_diff(prevstate);
    mu_ack.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_val.to_state(thestate);
    mu_ack.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ProcState& operator= (const mu_1_ProcState& from) {
    mu_state.value(from.mu_state.value());
    mu_val.value(from.mu_val.value());
    mu_ack.value(from.mu_ack.value());
    return *this;
  };
};

  void mu_1_ProcState::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ProcState::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ProcState::set_self(char *n, int os)
{
  name = n;
  mu_state.set_self_2(name, ".state", os + 0 );
  mu_val.set_self_2(name, ".val", os + 8 );
  mu_ack.set_self_2(name, ".ack", os + 16 );
}

mu_1_ProcState::~mu_1_ProcState()
{
}

/*** end record declaration ***/
mu_1_ProcState mu_1_ProcState_undefined_var;

class mu_1__type_3
{
 public:
  mu_1_ProcState array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_3 (char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1_ProcState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 2 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Proc is internally represented from 2 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
    for (int i = 0; i < 2; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_3::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_3::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_3::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Proc_1", i * 48 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 48 + os);i++;
}
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_4_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_4_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_4_id () : mu__byte(0,3,0) {};
  mu_1__type_4_id (int val) : mu__byte(0,3,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_4
{
 public:
  mu_1_Message array[ 4 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 4 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_4 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_4 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_4 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 3) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_4& operator= (const mu_1__type_4& from)
  {
    for (int i = 0; i < 4; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 4; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 4; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 4; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 4; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 4; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_4_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 4; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 4; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Message &element)
  {
    update_size();
    if (current_size >= 4) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 4; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_4_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Message temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 4; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 4; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 4; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_4::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_4::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_4::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 4; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 64 + os);
  k = os + i * 64;
  for(i = 0; i < 4; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_4::~mu_1__type_4()
{
}
/*** end multiset declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5
{
 public:
  mu_1__type_4 array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_5 (char *n, int os) { set_self(n, os); };
  mu_1__type_5 ( void ) {};
  virtual ~mu_1__type_5 ();
  mu_1__type_4& operator[] (int index) /* const */
  {
    if ( ( index >= 4 ) && ( index <= 4 ) )
      return array[ index - (4) ];
    if ( ( index >= 1 ) && ( index <= 2 ) )
      return array[ index - (0) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_5::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_5::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"HomeType", i * 288 + os);i++;
array[i].set_self_ar(n,"Proc_1", i * 288 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 288 + os);i++;
}
mu_1__type_5::~mu_1__type_5()
{
}
/*** end array declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1__type_6
{
 public:
  mu_1_Message array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_6 (char *n, int os) { set_self(n, os); };
  mu_1__type_6 ( void ) {};
  virtual ~mu_1__type_6 ();
  mu_1_Message& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
        Error.Error("Indexing to %s using an undefined value.", name);
      else
        Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_6& operator= (const mu_1__type_6& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_6::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_6::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_6::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 64 + os);
    delete[] s;
  }
};
mu_1__type_6::~mu_1__type_6()
{
}
/*** end array declaration ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1__type_7
{
 public:
  mu_1__type_6 array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_7 (char *n, int os) { set_self(n, os); };
  mu_1__type_7 ( void ) {};
  virtual ~mu_1__type_7 ();
  mu_1__type_6& operator[] (int index) /* const */
  {
    if ( ( index >= 4 ) && ( index <= 4 ) )
      return array[ index - (4) ];
    if ( ( index >= 1 ) && ( index <= 2 ) )
      return array[ index - (0) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_7& operator= (const mu_1__type_7& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_7& a, mu_1__type_7& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_7::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_7::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_7::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"HomeType", i * 192 + os);i++;
array[i].set_self_ar(n,"Proc_1", i * 192 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 192 + os);i++;
}
mu_1__type_7::~mu_1__type_7()
{
}
/*** end array declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1__type_8: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_8& val) { return mu__byte::operator=((int) val); };
  mu_1__type_8 (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1__type_8 (void): mu__byte(0, 2, 2) {};
  mu_1__type_8 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_8 mu_1__type_8_undefined_var;

const int mu_ProcCount = 2;
const int mu_ValueCount = 1;
const int mu_VC0 = 0;
const int mu_VC1 = 1;
const int mu_VC2 = 2;
const int mu_QMax = 2;
const int mu_NumVCs = 3;
const int mu_NetMax = 4;
const int mu_Proc_1 = 1;
const int mu_Proc_2 = 2;
const int mu_Value_1 = 3;
const int mu_HomeType = 4;
const int mu_GetS = 5;
const int mu_GetData = 6;
const int mu_GetM = 7;
const int mu_Inv = 8;
const int mu_Inv_Ack = 9;
const int mu_PutM = 10;
const int mu_PutS = 11;
const int mu_Put_Ack = 12;
const int mu_Fwd_GetS = 13;
const int mu_Fwd_GetM = 14;
const int mu_Put_Ack_Back = 15;
const int mu_GetData_Ack = 16;
const int mu_H_Invalid = 17;
const int mu_H_Modified = 18;
const int mu_H_Shared = 19;
const int mu_HT_S_D = 20;
const int mu_HT_M_D = 21;
const int mu_HT_M_P = 22;
const int mu_HT_M_A = 23;
const int mu_HT_S_P = 24;
const int mu_HT_I_P = 25;
const int mu_HT_M_ADa = 26;
const int mu_HT_M_Da = 27;
const int mu_P_Invalid = 28;
const int mu_P_Shared = 29;
const int mu_P_Modified = 30;
const int mu_PT_IS_D = 31;
const int mu_PT_IM_AD = 32;
const int mu_PT_IM_A = 33;
const int mu_PT_SM_AD = 34;
const int mu_PT_SM_A = 35;
const int mu_PT_MI_A = 36;
const int mu_PT_SI_A = 37;
const int mu_PT_II_A = 38;
/*** Variable declaration ***/
mu_1_HomeState mu_HomeNode("HomeNode",0);

/*** Variable declaration ***/
mu_1__type_3 mu_Procs("Procs",88);

/*** Variable declaration ***/
mu_1__type_5 mu_Net("Net",184);

/*** Variable declaration ***/
mu_1__type_7 mu_InBox("InBox",1048);

/*** Variable declaration ***/
mu_0_boolean mu_msg_processed("msg_processed",1624);

/*** Variable declaration ***/
mu_1_Value mu_LastWrite("LastWrite",1632);

void mu_Send(const mu_1_MessageType& mu_mtype, const mu_1_Node& mu_dst, const mu_1_Node& mu_src, const mu_1_VCType& mu_vc, const mu_1_Value& mu_val, const mu_1_AckType& mu_ack)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

/*** begin multisetcount 0 declaration ***/
  int mu__intexpr9 = 0;
  {
  mu_1__type_4_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net[mu_dst].valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr9++;
        }
      if (mu_i == 4-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
if ( !((mu__intexpr9) < (mu_NetMax)) ) Error.Error("Assertion failed: Too many messages");
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_vc.isundefined())
  mu_msg.mu_vc.undefine();
else
  mu_msg.mu_vc = mu_vc;
if (mu_val.isundefined())
  mu_msg.mu_val.undefine();
else
  mu_msg.mu_val = mu_val;
if (mu_ack.isundefined())
  mu_msg.mu_ack.undefine();
else
  mu_msg.mu_ack = mu_ack;
mu_Net[mu_dst].multisetadd(mu_msg);
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledMsg(mu_1_Message& mu_msg, const mu_1_Node& mu_n)
{
Error.Error("Error: Unhandled message type!");
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledState()
{
Error.Error("Error: Unhandled state!");
};
/*** end procedure declaration ***/

void mu_AddToSharersList(const mu_1_Node& mu_n)
{
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr10 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNode.mu_sharers[mu_i]) == (mu_n) ) mu__intexpr10++;
        }
      if (mu_i == 2-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
if ( (mu__intexpr10) == (0) )
{
mu_HomeNode.mu_sharers.multisetadd(mu_n);
}
};
/*** end procedure declaration ***/

mu_0_boolean mu_IsSharer(const mu_1_Node& mu_n)
{
/*** begin multisetcount 2 declaration ***/
  int mu__intexpr11 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNode.mu_sharers[mu_i]) == (mu_n) ) mu__intexpr11++;
        }
      if (mu_i == 2-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
return (mu__intexpr11) > (0);
  Error.Error("The end of function IsSharer reached without returning values.");
};
/*** end function declaration ***/

void mu_RemoveFromSharersList(const mu_1_Node& mu_n)
{
/*** end multisetremove 0 declaration ***/
  mu_1__type_1_id mu__idexpr12;
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNode.mu_sharers[mu_i]) == (mu_n) ) { mu__idexpr12 = mu_i; mu_HomeNode.mu_sharers.multisetremove(mu__idexpr12); };
        }
      if (mu_i == 2-1) break;
    }
/*** end multisetremove 0 declaration ***/
};
/*** end procedure declaration ***/

void mu_RemoveAllSharersList()
{
{
for(int mu_n = 1; mu_n <= 4; mu_n++)
  if (( ( mu_n >= 1 ) && ( mu_n <= 2 ) )|| ( ( mu_n >= 4 ) && ( mu_n <= 4 ) )) {
mu_RemoveFromSharersList ( mu_n );
};
};
};
/*** end procedure declaration ***/

void mu_SendInvReqToSharers(const mu_1_Node& mu_rqst)
{
{
for(int mu_n = 1; mu_n <= 4; mu_n++)
  if (( ( mu_n >= 1 ) && ( mu_n <= 2 ) )|| ( ( mu_n >= 4 ) && ( mu_n <= 4 ) )) {
bool mu__boolexpr13;
  if (!((mu_n>=1 && mu_n<=2))) mu__boolexpr13 = FALSE ;
  else {
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr14 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNode.mu_sharers[mu_i]) == (mu_n) ) mu__intexpr14++;
        }
      if (mu_i == 2-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
  mu__boolexpr13 = ((mu__intexpr14) != (0)) ; 
}
if ( mu__boolexpr13 )
{
if ( (mu_n) != (mu_rqst) )
{
mu_Send ( mu_Inv, mu_n, mu_rqst, mu_VC1, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Inv to ";
cout << ( mu_n );
cout << "\n";
}
}
};
};
};
/*** end procedure declaration ***/

void mu_print()
{
cout << "---------------------------------\n";
mu_HomeNode.mu_state.print();
{
for(int mu_n = 1; mu_n <= 2; mu_n++) {
mu_Procs[mu_n].mu_state.print();
};
};
{
for(int mu_n = 1; mu_n <= 2; mu_n++) {
/*** begin multisetcount 4 declaration ***/
  int mu__intexpr15 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNode.mu_sharers[mu_i]) == (mu_n) ) mu__intexpr15++;
        }
      if (mu_i == 2-1) break;
    }
  }
/*** end multisetcount 4 declaration ***/
cout << ( mu__intexpr15 );
cout << " ";
};
};
cout << "\n";
};
/*** end procedure declaration ***/

void mu_print2()
{
mu_HomeNode.mu_state.print();
{
for(int mu_n = 1; mu_n <= 2; mu_n++) {
mu_Procs[mu_n].mu_state.print();
};
};
{
for(int mu_n = 1; mu_n <= 2; mu_n++) {
/*** begin multisetcount 5 declaration ***/
  int mu__intexpr16 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNode.mu_sharers[mu_i]) == (mu_n) ) mu__intexpr16++;
        }
      if (mu_i == 2-1) break;
    }
  }
/*** end multisetcount 5 declaration ***/
cout << ( mu__intexpr16 );
cout << " ";
};
};
cout << "\n=================================\n";
};
/*** end procedure declaration ***/

void mu_HomeReceive(mu_1_Message& mu_msg)
{
/*** Variable declaration ***/
mu_1__type_8 mu_cnt("cnt",0);

cout << "Home Receiving ";
cout << ( mu_msg.mu_mtype );
cout << " from ";
cout << ( mu_msg.mu_src );
cout << " on VC";
cout << ( mu_msg.mu_vc );
cout << "\n home --    ";
mu_HomeNode.mu_state.print();
/*** begin multisetcount 6 declaration ***/
  int mu__intexpr17 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr17++;
        }
      if (mu_i == 2-1) break;
    }
  }
/*** end multisetcount 6 declaration ***/
mu_cnt = mu__intexpr17;
mu_msg_processed = mu_true;
switch ((int) mu_HomeNode.mu_state) {
case mu_H_Invalid:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_HomeNode.mu_state = mu_H_Shared;
mu_Send ( mu_GetData, mu_msg.mu_src, (int)mu_HomeType, mu_VC0, mu_HomeNode.mu_val, 0 );
cout << "Send GetData to ";
cout << ( mu_msg.mu_src );
cout << " ack=0\n";
mu_AddToSharersList ( mu_msg.mu_src );
break;
case mu_GetM:
mu_HomeNode.mu_state = mu_H_Modified;
mu_RemoveAllSharersList (  );
mu_HomeNode.mu_owner = mu_msg.mu_src;
mu_Send ( mu_GetData, mu_msg.mu_src, (int)mu_HomeType, mu_VC0, mu_HomeNode.mu_val, (int)mu_cnt );
cout << "Send GetData to ";
cout << ( mu_msg.mu_src );
cout << " ack=";
mu_cnt.print();
cout << "\n";
break;
case mu_PutS:
mu_Send ( mu_Put_Ack, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Put_Ack to ";
cout << ( mu_msg.mu_src );
cout << "\n";
mu_HomeNode.mu_state = mu_HT_I_P;
break;
case mu_PutM:
if ( (mu_msg.mu_src) != (mu_HomeNode.mu_owner) )
{
mu_Send ( mu_Put_Ack, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Put_Ack to ";
cout << ( mu_msg.mu_src );
cout << "\n";
mu_HomeNode.mu_state = mu_HT_I_P;
}
else
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
}
break;
case mu_H_Shared:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_Send ( mu_GetData, mu_msg.mu_src, (int)mu_HomeType, mu_VC0, mu_HomeNode.mu_val, 0 );
cout << "Send GetData to ";
cout << ( mu_msg.mu_src );
cout << " ack=0\n";
mu_AddToSharersList ( mu_msg.mu_src );
break;
case mu_GetM:
mu_HomeNode.mu_owner = mu_msg.mu_src;
if ( mu_IsSharer( mu_msg.mu_src ) )
{
mu_Send ( mu_GetData, mu_msg.mu_src, (int)mu_HomeType, mu_VC0, mu_HomeNode.mu_val, (mu_cnt) - (1) );
cout << "Send GetData to ";
cout << ( mu_msg.mu_src );
cout << " ack=";
cout << ( (mu_cnt) - (1) );
cout << "\n";
if ( (mu_cnt) == (1) )
{
mu_HomeNode.mu_state = mu_H_Modified;
mu_RemoveAllSharersList (  );
}
else
{
mu_HomeNode.mu_state = mu_HT_M_ADa;
}
}
else
{
mu_Send ( mu_GetData, mu_msg.mu_src, (int)mu_HomeType, mu_VC0, mu_HomeNode.mu_val, (int)mu_cnt );
cout << "Send GetData to ";
cout << ( mu_msg.mu_src );
cout << " ack=";
mu_cnt.print();
cout << "\n";
if ( (mu_cnt) == (0) )
{
mu_HomeNode.mu_state = mu_H_Modified;
mu_RemoveAllSharersList (  );
}
else
{
mu_HomeNode.mu_state = mu_HT_M_ADa;
}
}
mu_SendInvReqToSharers ( mu_msg.mu_src );
mu_RemoveFromSharersList ( mu_msg.mu_src );
break;
case mu_PutS:
if ( mu_IsSharer( mu_msg.mu_src ) )
{
mu_RemoveFromSharersList ( mu_msg.mu_src );
mu_Send ( mu_Put_Ack, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Put_Ack to ";
cout << ( mu_msg.mu_src );
cout << "\n";
/*** begin multisetcount 7 declaration ***/
  int mu__intexpr18 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNode.mu_sharers[mu_i]) == (mu_msg.mu_src) ) mu__intexpr18++;
        }
      if (mu_i == 2-1) break;
    }
  }
/*** end multisetcount 7 declaration ***/
if ( (mu__intexpr18) == (1) )
{
mu_HomeNode.mu_state = mu_HT_I_P;
}
else
{
mu_HomeNode.mu_state = mu_HT_S_P;
}
}
else
{
mu_Send ( mu_Put_Ack, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Put_Ack to ";
cout << ( mu_msg.mu_src );
cout << "\n";
/*** begin multisetcount 8 declaration ***/
  int mu__intexpr19 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_HomeNode.mu_sharers[mu_i]) == (mu_msg.mu_src) ) mu__intexpr19++;
        }
      if (mu_i == 2-1) break;
    }
  }
/*** end multisetcount 8 declaration ***/
if ( (mu__intexpr19) == (1) )
{
mu_HomeNode.mu_state = mu_HT_I_P;
}
else
{
mu_HomeNode.mu_state = mu_HT_S_P;
}
}
break;
case mu_PutM:
if ( (mu_msg.mu_src) != (mu_HomeNode.mu_owner) )
{
mu_RemoveFromSharersList ( mu_msg.mu_src );
mu_Send ( mu_Put_Ack, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Put_Ack to ";
cout << ( mu_msg.mu_src );
cout << "\n";
mu_HomeNode.mu_state = mu_HT_S_P;
}
else
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
}
break;
case mu_H_Modified:
if ( !((mu_HomeNode.mu_owner.isundefined()) == (mu_false)) ) Error.Error("Assertion failed: HomeNode has no owner, but line is Modified");
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_Send ( mu_Fwd_GetS, mu_HomeNode.mu_owner, mu_msg.mu_src, mu_VC1, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Fwd_GetS to ";
mu_HomeNode.mu_owner.print();
mu_AddToSharersList ( mu_msg.mu_src );
mu_AddToSharersList ( mu_HomeNode.mu_owner );
mu_HomeNode.mu_owner.undefine();
mu_HomeNode.mu_state = mu_HT_S_D;
break;
case mu_GetM:
mu_Send ( mu_Fwd_GetM, mu_HomeNode.mu_owner, mu_msg.mu_src, mu_VC1, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Fwd_GetM to ";
mu_HomeNode.mu_owner.print();
mu_HomeNode.mu_owner = mu_msg.mu_src;
mu_HomeNode.mu_state = mu_HT_M_D;
break;
case mu_PutS:
mu_Send ( mu_Put_Ack, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Put_Ack to ";
cout << ( mu_msg.mu_src );
cout << "\n";
mu_HomeNode.mu_state = mu_HT_M_P;
break;
case mu_PutM:
mu_Send ( mu_Put_Ack, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Put_Ack to ";
cout << ( mu_msg.mu_src );
cout << "\n";
if ( (mu_msg.mu_src) == (mu_HomeNode.mu_owner) )
{
if ( !(!(mu_HomeNode.mu_owner.isundefined())) ) Error.Error("Assertion failed: owner undefined");
mu_HomeNode.mu_state = mu_HT_I_P;
mu_HomeNode.mu_val = mu_msg.mu_val;
mu_LastWrite = mu_HomeNode.mu_val;
mu_HomeNode.mu_owner.undefine();
mu_RemoveAllSharersList (  );
}
else
{
mu_HomeNode.mu_state = mu_HT_M_P;
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
}
break;
case mu_HT_S_D:
switch ((int) mu_msg.mu_mtype) {
case mu_GetData:
mu_HomeNode.mu_state = mu_H_Shared;
mu_HomeNode.mu_val = mu_msg.mu_val;
mu_LastWrite = mu_HomeNode.mu_val;
break;
default:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
}
break;
case mu_HT_M_ADa:
switch ((int) mu_msg.mu_mtype) {
case mu_GetData_Ack:
mu_HomeNode.mu_state = mu_HT_M_A;
break;
case mu_Inv_Ack:
if ( mu_HomeNode.mu_ack.isundefined() )
{
mu_HomeNode.mu_ack = 1;
}
else
{
mu_HomeNode.mu_ack = (mu_HomeNode.mu_ack) + (1);
}
mu_HomeNode.mu_ack.print();
mu_cnt.print();
if ( (mu_HomeNode.mu_ack) == (mu_cnt) )
{
mu_HomeNode.mu_state = mu_HT_M_Da;
}
break;
default:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
}
break;
case mu_HT_M_Da:
switch ((int) mu_msg.mu_mtype) {
case mu_GetData_Ack:
mu_HomeNode.mu_state = mu_H_Modified;
mu_HomeNode.mu_ack.undefine();
mu_RemoveAllSharersList (  );
break;
default:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
}
break;
case mu_HT_M_D:
switch ((int) mu_msg.mu_mtype) {
case mu_GetData:
mu_HomeNode.mu_state = mu_H_Modified;
mu_HomeNode.mu_ack.undefine();
mu_RemoveAllSharersList (  );
break;
default:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
}
break;
case mu_HT_M_P:
switch ((int) mu_msg.mu_mtype) {
case mu_Put_Ack_Back:
mu_HomeNode.mu_state = mu_H_Modified;
mu_HomeNode.mu_ack.undefine();
mu_RemoveAllSharersList (  );
break;
default:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
}
break;
case mu_HT_M_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv_Ack:
if ( mu_HomeNode.mu_ack.isundefined() )
{
mu_HomeNode.mu_ack = 1;
}
else
{
mu_HomeNode.mu_ack = (mu_HomeNode.mu_ack) + (1);
}
mu_HomeNode.mu_ack.print();
mu_cnt.print();
if ( (mu_HomeNode.mu_ack) == (mu_cnt) )
{
mu_HomeNode.mu_state = mu_H_Modified;
mu_HomeNode.mu_ack.undefine();
mu_RemoveAllSharersList (  );
}
break;
default:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
}
break;
case mu_HT_S_P:
switch ((int) mu_msg.mu_mtype) {
case mu_Put_Ack_Back:
mu_HomeNode.mu_state = mu_H_Shared;
break;
default:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
}
break;
case mu_HT_I_P:
switch ((int) mu_msg.mu_mtype) {
case mu_Put_Ack_Back:
mu_HomeNode.mu_state = mu_H_Invalid;
mu_HomeNode.mu_ack.undefine();
mu_RemoveAllSharersList (  );
break;
default:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
}
break;
}
cout << " changes to ";
mu_HomeNode.mu_state.print();
cout << "\n";
};
/*** end procedure declaration ***/

void mu_ProcReceive(mu_1_Message& mu_msg, const mu_1_Proc& mu_p)
{
cout << "Proc_";
cout << ( mu_p );
cout << " Receiving ";
cout << ( mu_msg.mu_mtype );
cout << " from ";
cout << ( mu_msg.mu_src );
cout << " on VC";
cout << ( mu_msg.mu_vc );
cout << "\n";
mu_msg_processed = mu_true;
{
  mu_1__type_2& mu_ps = mu_Procs[mu_p].mu_state;
{
  mu_1_Value& mu_pv = mu_Procs[mu_p].mu_val;
cout << " Proc --    ";
mu_ps.print();
switch ((int) mu_ps) {
case mu_P_Invalid:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
case mu_P_Shared:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
mu_Send ( mu_Inv_Ack, mu_msg.mu_src, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Inv_Ack to ";
cout << ( mu_msg.mu_src );
cout << "\n";
mu_Send ( mu_Inv_Ack, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Inv_Ack to ";
cout << ( mu_HomeType );
cout << "\n";
mu_ps = mu_P_Invalid;
mu_pv.undefine();
mu_Procs[mu_p].mu_ack.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_P_Modified:
switch ((int) mu_msg.mu_mtype) {
case mu_Fwd_GetS:
mu_Send ( mu_GetData, mu_msg.mu_src, (int)mu_p, mu_VC0, mu_pv, mu_1_AckType_undefined_var );
cout << "Send GetData to ";
cout << ( mu_msg.mu_src );
cout << "\n";
mu_Send ( mu_GetData, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_pv, mu_1_AckType_undefined_var );
cout << "Send GetData to ";
cout << ( mu_HomeType );
cout << "\n";
mu_ps = mu_P_Shared;
break;
case mu_Fwd_GetM:
mu_Send ( mu_GetData, mu_msg.mu_src, (int)mu_p, mu_VC0, mu_pv, mu_1_AckType_undefined_var );
cout << "Send GetData to ";
cout << ( mu_msg.mu_src );
cout << "\n";
mu_Send ( mu_GetData, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send GetData to ";
cout << ( mu_HomeType );
cout << "\n";
mu_ps = mu_P_Invalid;
mu_pv.undefine();
mu_Procs[mu_p].mu_ack.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_IS_D:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
case mu_GetData:
mu_pv = mu_msg.mu_val;
mu_LastWrite = mu_pv;
if ( (mu_msg.mu_src>=1 && mu_msg.mu_src<=2) )
{
mu_ps = mu_P_Shared;
mu_Procs[mu_p].mu_ack.undefine();
}
else
{
if ( !(mu_msg.mu_ack.isundefined()) )
{
if ( (mu_msg.mu_ack) == (0) )
{
mu_ps = mu_P_Shared;
mu_Procs[mu_p].mu_ack.undefine();
}
else
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
}
}
else
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
}
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_IM_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_Fwd_GetM:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
case mu_Fwd_GetS:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
case mu_GetData:
mu_pv = mu_msg.mu_val;
mu_LastWrite = mu_pv;
if ( (mu_msg.mu_src>=1 && mu_msg.mu_src<=2) )
{
mu_ps = mu_P_Modified;
mu_Procs[mu_p].mu_ack.undefine();
}
else
{
if ( (mu_msg.mu_ack) == (0) )
{
mu_ps = mu_P_Modified;
mu_Procs[mu_p].mu_ack.undefine();
mu_Send ( mu_GetData_Ack, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send GetDAta_Ack to ";
cout << ( mu_HomeType );
}
else
{
mu_ps = mu_PT_IM_A;
if ( mu_Procs[mu_p].mu_ack.isundefined() )
{
mu_Procs[mu_p].mu_ack = mu_msg.mu_ack;
}
else
{
if ( ((mu_Procs[mu_p].mu_ack) + (mu_msg.mu_ack)) == (0) )
{
mu_ps = mu_P_Modified;
mu_Procs[mu_p].mu_ack.undefine();
mu_Send ( mu_GetData_Ack, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send GetDAta_Ack to ";
cout << ( mu_HomeType );
}
else
{
mu_Procs[mu_p].mu_ack = (mu_Procs[mu_p].mu_ack) + (mu_msg.mu_ack);
}
}
}
}
break;
case mu_Inv_Ack:
if ( mu_Procs[mu_p].mu_ack.isundefined() )
{
mu_Procs[mu_p].mu_ack = -1;
}
else
{
mu_Procs[mu_p].mu_ack = (mu_Procs[mu_p].mu_ack) - (1);
}
mu_Procs[mu_p].mu_ack.print();
cout << "\n";
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_IM_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Fwd_GetM:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
case mu_Fwd_GetS:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
case mu_Inv_Ack:
if ( mu_Procs[mu_p].mu_ack.isundefined() )
{
mu_Procs[mu_p].mu_ack = -1;
}
else
{
if ( (mu_Procs[mu_p].mu_ack) == (1) )
{
mu_ps = mu_P_Modified;
mu_Procs[mu_p].mu_ack.undefine();
mu_Send ( mu_GetData_Ack, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send GetDAta_Ack to ";
cout << ( mu_HomeType );
}
else
{
mu_Procs[mu_p].mu_ack = (mu_Procs[mu_p].mu_ack) - (1);
}
}
mu_Procs[mu_p].mu_ack.print();
cout << "\n";
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_SM_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_Fwd_GetM:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
case mu_Fwd_GetS:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
case mu_Inv:
mu_Send ( mu_Inv_Ack, mu_msg.mu_src, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Inv_Ack to ";
cout << ( mu_msg.mu_src );
cout << "\n";
mu_Send ( mu_Inv_Ack, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Inv_Ack to ";
cout << ( mu_HomeType );
cout << "\n";
mu_ps = mu_PT_IM_AD;
break;
case mu_GetData:
mu_pv = mu_msg.mu_val;
mu_LastWrite = mu_pv;
if ( (mu_msg.mu_src>=1 && mu_msg.mu_src<=2) )
{
mu_ps = mu_P_Modified;
mu_Procs[mu_p].mu_ack.undefine();
}
else
{
if ( (mu_msg.mu_ack) == (0) )
{
mu_ps = mu_P_Modified;
mu_Procs[mu_p].mu_ack.undefine();
}
else
{
mu_ps = mu_PT_SM_A;
if ( mu_Procs[mu_p].mu_ack.isundefined() )
{
mu_Procs[mu_p].mu_ack = mu_msg.mu_ack;
}
else
{
if ( ((mu_Procs[mu_p].mu_ack) + (mu_msg.mu_ack)) == (0) )
{
mu_ps = mu_P_Modified;
mu_Procs[mu_p].mu_ack.undefine();
mu_Send ( mu_GetData_Ack, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send GetDAta_Ack to ";
cout << ( mu_HomeType );
}
else
{
mu_Procs[mu_p].mu_ack = (mu_Procs[mu_p].mu_ack) + (mu_msg.mu_ack);
}
}
mu_Procs[mu_p].mu_ack.print();
cout << "\n";
}
}
break;
case mu_Inv_Ack:
if ( mu_Procs[mu_p].mu_ack.isundefined() )
{
mu_Procs[mu_p].mu_ack = -1;
mu_Procs[mu_p].mu_ack.print();
cout << "\n";
}
else
{
mu_Procs[mu_p].mu_ack = (mu_Procs[mu_p].mu_ack) - (1);
mu_Procs[mu_p].mu_ack.print();
cout << "\n";
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_SM_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Fwd_GetS:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
case mu_Fwd_GetM:
mu_msg_processed = mu_false;
cout << "store in box\n";
break;
case mu_Inv_Ack:
if ( mu_Procs[mu_p].mu_ack.isundefined() )
{
mu_Procs[mu_p].mu_ack = -1;
}
else
{
if ( (mu_Procs[mu_p].mu_ack) == (1) )
{
mu_ps = mu_P_Modified;
mu_Procs[mu_p].mu_ack.undefine();
mu_Send ( mu_GetData_Ack, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send GetDAta_Ack to ";
cout << ( mu_HomeType );
}
else
{
mu_Procs[mu_p].mu_ack = (mu_Procs[mu_p].mu_ack) - (1);
}
}
mu_Procs[mu_p].mu_ack.print();
cout << "\n";
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_MI_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Fwd_GetS:
mu_Send ( mu_GetData, mu_msg.mu_src, (int)mu_p, mu_VC0, mu_pv, mu_1_AckType_undefined_var );
cout << "Send GetData to ";
cout << ( mu_msg.mu_src );
cout << "\n";
mu_Send ( mu_GetData, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_pv, mu_1_AckType_undefined_var );
cout << "Send GetData to ";
cout << ( mu_HomeType );
cout << "\n";
mu_ps = mu_PT_SI_A;
break;
case mu_Fwd_GetM:
mu_Send ( mu_GetData, mu_msg.mu_src, (int)mu_p, mu_VC0, mu_pv, mu_1_AckType_undefined_var );
cout << "Send GetData to ";
cout << ( mu_msg.mu_src );
cout << "\n";
mu_Send ( mu_GetData, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send GetData to ";
cout << ( mu_HomeType );
cout << "\n";
mu_ps = mu_PT_II_A;
break;
case mu_Put_Ack:
mu_ps = mu_P_Invalid;
mu_pv.undefine();
mu_Procs[mu_p].mu_ack.undefine();
mu_Send ( mu_Put_Ack_Back, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Put_Ack_Back to ";
cout << ( mu_HomeType );
cout << "\n";
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_SI_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
mu_Send ( mu_Inv_Ack, mu_msg.mu_src, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Inv_Ack to ";
cout << ( mu_msg.mu_src );
cout << "\n";
mu_Send ( mu_Inv_Ack, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Inv_Ack to ";
cout << ( mu_HomeType );
cout << "\n";
mu_ps = mu_PT_II_A;
break;
case mu_Put_Ack:
mu_ps = mu_P_Invalid;
mu_pv.undefine();
mu_Procs[mu_p].mu_ack.undefine();
mu_Send ( mu_Put_Ack_Back, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Put_Ack_Back to ";
cout << ( mu_HomeType );
cout << "\n";
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PT_II_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Put_Ack:
mu_ps = mu_P_Invalid;
mu_pv.undefine();
mu_Procs[mu_p].mu_ack.undefine();
mu_Send ( mu_Put_Ack_Back, (int)mu_HomeType, (int)mu_p, mu_VC0, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send Put_Ack_Back to ";
cout << ( mu_HomeType );
cout << "\n";
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
default:
mu_ErrorUnhandledState (  );
break;
}
cout << "msg.ack = ";
cout << ( mu_msg.mu_ack );
cout << "\n";
cout << " changes to ";
mu_ps.print();
cout << "\n";
}
}
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_HomeNode.clear();
  mu_Procs.clear();
  mu_Net.clear();
  mu_InBox.clear();
  mu_msg_processed.clear();
  mu_LastWrite.clear();
}
void world_class::undefine()
{
  mu_HomeNode.undefine();
  mu_Procs.undefine();
  mu_Net.undefine();
  mu_InBox.undefine();
  mu_msg_processed.undefine();
  mu_LastWrite.undefine();
}
void world_class::reset()
{
  mu_HomeNode.reset();
  mu_Procs.reset();
  mu_Net.reset();
  mu_InBox.reset();
  mu_msg_processed.reset();
  mu_LastWrite.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_HomeNode.print();
  mu_Procs.print();
  mu_Net.print();
  mu_InBox.print();
  mu_msg_processed.print();
  mu_LastWrite.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_HomeNode.print_statistic();
  mu_Procs.print_statistic();
  mu_Net.print_statistic();
  mu_InBox.print_statistic();
  mu_msg_processed.print_statistic();
  mu_LastWrite.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_HomeNode.print_diff(prevstate);
    mu_Procs.print_diff(prevstate);
    mu_Net.print_diff(prevstate);
    mu_InBox.print_diff(prevstate);
    mu_msg_processed.print_diff(prevstate);
    mu_LastWrite.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_HomeNode.to_state( newstate );
  mu_Procs.to_state( newstate );
  mu_Net.to_state( newstate );
  mu_InBox.to_state( newstate );
  mu_msg_processed.to_state( newstate );
  mu_LastWrite.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 3);
    r = r / 3;
    return tsprintf("receive-blocked-vc, vc:%s, n:%s", mu_vc.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 3);
    r = r / 3;
  return !(mu_InBox[mu_n][mu_vc].mu_mtype.isundefined());
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 3);
    r = r / 3;
    while (what_rule < 9 )
      {
        if ( ( TRUE  ) ) {
              if (!(mu_InBox[mu_n][mu_vc].mu_mtype.isundefined())) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 0;
    mu_vc.value((r % 3) + 0);
    r = r / 3;
    mu_n.unionassign(r % 3);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 3);
    r = r / 3;
mu_print (  );
if ( (mu_n>=4 && mu_n<=4) )
{
mu_HomeReceive ( mu_InBox[mu_n][mu_vc] );
}
else
{
mu_ProcReceive ( mu_InBox[mu_n][mu_vc], (int)mu_n );
}
mu_print2 (  );
if ( mu_msg_processed )
{
mu_InBox[mu_n][mu_vc].undefine();
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 3);
    r = r / 3;
    return tsprintf("receive-net, midx:%s, n:%s", mu_midx.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 3);
    r = r / 3;
  if (!mu_Net[mu_n].in(mu_midx)) { return FALSE; }
  mu_1__type_4& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
  mu_1__type_6& mu_box = mu_InBox[mu_n];
  return mu_box[mu_msg.mu_vc].mu_mtype.isundefined();
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 9;
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 3);
    r = r / 3;
    while (what_rule < 21 && mu_midx.value()<4 )
      {
        if ( ( TRUE && mu_Net[mu_n].in(mu_midx) ) ) {
  mu_1__type_4& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
  mu_1__type_6& mu_box = mu_InBox[mu_n];
              if (mu_box[mu_msg.mu_vc].mu_mtype.isundefined()) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 9;
    mu_midx.value((r % 4) + 0);
    r = r / 4;
    mu_n.unionassign(r % 3);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_4_id mu_midx;
    mu_midx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 3);
    r = r / 3;
  mu_1__type_4& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
  mu_1__type_6& mu_box = mu_InBox[mu_n];
mu_print (  );
if ( (mu_n>=4 && mu_n<=4) )
{
mu_HomeReceive ( mu_msg );
}
else
{
mu_ProcReceive ( mu_msg, (int)mu_n );
}
mu_print2 (  );
if ( !(mu_msg_processed) )
{
mu_box[mu_msg.mu_vc] = mu_msg;
}
mu_chan.multisetremove(mu_midx);
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 1);
    r = r / 2;
    return tsprintf("read request when P_Invalid, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 1);
    r = r / 2;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_Invalid);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 21;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 1);
    r = r / 2;
    while (what_rule < 23 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_Invalid)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 21;
    mu_n.value((r % 2) + 1);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 1);
    r = r / 2;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_print (  );
cout << ( mu_n );
cout << " read\n";
mu_Send ( mu_GetS, (int)mu_HomeType, (int)mu_n, mu_VC2, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send GetS to Home\n";
mu_p.mu_state = mu_PT_IS_D;
mu_print2 (  );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 1) + 3);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 1);
    r = r / 2;
    return tsprintf("store new value when P_Invalid, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 1) + 3);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 1);
    r = r / 2;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_P_Invalid);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 23;
    static mu_1_Value mu_v;
    mu_v.value((r % 1) + 3);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 1);
    r = r / 2;
    while (what_rule < 25 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_P_Invalid)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 23;
    mu_v.value((r % 1) + 3);
    r = r / 1;
    mu_n.value((r % 2) + 1);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 1) + 3);
    r = r / 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 2) + 1);
    r = r / 2;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_print (  );
cout << ( mu_n );
cout << " write\n";
mu_Send ( mu_GetM, (int)mu_HomeType, (int)mu_n, mu_VC2, mu_1_Value_undefined_var, mu_1_AckType_undefined_var );
cout << "Send GetM to Home\n";
mu_p.mu_state = mu_PT_IM_AD;
mu_print2 (  );
  };

  bool UnFair()
  { return FALSE; }
};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<9)
    { R0.NextRule(what_rule);
      if (what_rule<9) return; }
  if (what_rule>=9 && what_rule<21)
    { R1.NextRule(what_rule);
      if (what_rule<21) return; }
  if (what_rule>=21 && what_rule<23)
    { R2.NextRule(what_rule);
      if (what_rule<23) return; }
  if (what_rule>=23 && what_rule<25)
    { R3.NextRule(what_rule);
      if (what_rule<25) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=8) return R0.Condition(r-0);
  if (r>=9 && r<=20) return R1.Condition(r-9);
  if (r>=21 && r<=22) return R2.Condition(r-21);
  if (r>=23 && r<=24) return R3.Condition(r-23);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=8) { R0.Code(r-0); return; } 
  if (r>=9 && r<=20) { R1.Code(r-9); return; } 
  if (r>=21 && r<=22) { R2.Code(r-21); return; } 
  if (r>=23 && r<=24) { R3.Code(r-23); return; } 
}
int Priority(unsigned short r)
{
  if (r<=8) { return R0.Priority(); } 
  if (r>=9 && r<=20) { return R1.Priority(); } 
  if (r>=21 && r<=22) { return R2.Priority(); } 
  if (r>=23 && r<=24) { return R3.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=8) return R0.Name(r-0);
  if (r>=9 && r<=20) return R1.Name(r-9);
  if (r>=21 && r<=22) return R2.Name(r-21);
  if (r>=23 && r<=24) return R3.Name(r-23);
  return NULL;
}
};
const unsigned numrules = 25;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 25


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
{
for(int mu_v = 3; mu_v <= 3; mu_v++) {
mu_HomeNode.mu_state = mu_H_Invalid;
mu_HomeNode.mu_owner.undefine();
mu_HomeNode.mu_ack.undefine();
mu_HomeNode.mu_val = mu_v;
{
for(int mu_n = 1; mu_n <= 4; mu_n++)
  if (( ( mu_n >= 1 ) && ( mu_n <= 2 ) )|| ( ( mu_n >= 4 ) && ( mu_n <= 4 ) )) {
mu_RemoveFromSharersList ( mu_n );
};
};
};
};
mu_LastWrite = mu_HomeNode.mu_val;
{
for(int mu_i = 1; mu_i <= 2; mu_i++) {
mu_Procs[mu_i].mu_state = mu_P_Invalid;
mu_Procs[mu_i].mu_val.undefine();
mu_Procs[mu_i].mu_ack.undefine();
};
};
mu_Net.undefine();
  };

  bool UnFair()
  { return FALSE; }
};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_20() // Invariant "values in shared state match memory"
{
bool mu__quant21; 
mu__quant21 = TRUE;
{
for(int mu_n = 1; mu_n <= 2; mu_n++) {
bool mu__boolexpr22;
bool mu__boolexpr23;
  if (!((mu_HomeNode.mu_state) == (mu_H_Shared))) mu__boolexpr23 = FALSE ;
  else {
  mu__boolexpr23 = ((mu_Procs[mu_n].mu_state) == (mu_P_Shared)) ; 
}
  if (!(mu__boolexpr23)) mu__boolexpr22 = TRUE ;
  else {
  mu__boolexpr22 = ((mu_HomeNode.mu_val) == (mu_Procs[mu_n].mu_val)) ; 
}
if ( !(mu__boolexpr22) )
  { mu__quant21 = FALSE; break; }
};
};
return mu__quant21;
};

bool mu__condition_24() // Condition for Rule "values in shared state match memory"
{
  return mu__invariant_20( );
}

/**** end rule declaration ****/

int mu__invariant_25() // Invariant "Invalid implies empty sharer list"
{
bool mu__boolexpr26;
  if (!((mu_HomeNode.mu_state) == (mu_H_Invalid))) mu__boolexpr26 = TRUE ;
  else {
/*** begin multisetcount 10 declaration ***/
  int mu__intexpr27 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr27++;
        }
      if (mu_i == 2-1) break;
    }
  }
/*** end multisetcount 10 declaration ***/
  mu__boolexpr26 = ((mu__intexpr27) == (0)) ; 
}
return mu__boolexpr26;
};

bool mu__condition_28() // Condition for Rule "Invalid implies empty sharer list"
{
  return mu__invariant_25( );
}

/**** end rule declaration ****/

int mu__invariant_29() // Invariant "modified implies empty sharers list"
{
bool mu__boolexpr30;
  if (!((mu_HomeNode.mu_state) == (mu_H_Modified))) mu__boolexpr30 = TRUE ;
  else {
/*** begin multisetcount 9 declaration ***/
  int mu__intexpr31 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr31++;
        }
      if (mu_i == 2-1) break;
    }
  }
/*** end multisetcount 9 declaration ***/
  mu__boolexpr30 = ((mu__intexpr31) == (0)) ; 
}
return mu__boolexpr30;
};

bool mu__condition_32() // Condition for Rule "modified implies empty sharers list"
{
  return mu__invariant_29( );
}

/**** end rule declaration ****/

int mu__invariant_33() // Invariant "value is undefined while invalid"
{
bool mu__quant34; 
mu__quant34 = TRUE;
{
for(int mu_n = 1; mu_n <= 2; mu_n++) {
bool mu__boolexpr35;
  if (!((mu_Procs[mu_n].mu_state) == (mu_P_Invalid))) mu__boolexpr35 = TRUE ;
  else {
  mu__boolexpr35 = (mu_Procs[mu_n].mu_val.isundefined()) ; 
}
if ( !(mu__boolexpr35) )
  { mu__quant34 = FALSE; break; }
};
};
return mu__quant34;
};

bool mu__condition_36() // Condition for Rule "value is undefined while invalid"
{
  return mu__invariant_33( );
}

/**** end rule declaration ****/

int mu__invariant_37() // Invariant "values in modified state match last write"
{
bool mu__quant38; 
mu__quant38 = TRUE;
{
for(int mu_n = 1; mu_n <= 2; mu_n++) {
bool mu__boolexpr39;
  if (!((mu_Procs[mu_n].mu_state) == (mu_P_Modified))) mu__boolexpr39 = TRUE ;
  else {
  mu__boolexpr39 = ((mu_Procs[mu_n].mu_val) == (mu_LastWrite)) ; 
}
if ( !(mu__boolexpr39) )
  { mu__quant38 = FALSE; break; }
};
};
return mu__quant38;
};

bool mu__condition_40() // Condition for Rule "values in modified state match last write"
{
  return mu__invariant_37( );
}

/**** end rule declaration ****/

int mu__invariant_41() // Invariant "value in memory matches value of last write, when invalid"
{
bool mu__boolexpr42;
  if (!((mu_HomeNode.mu_state) == (mu_H_Invalid))) mu__boolexpr42 = TRUE ;
  else {
  mu__boolexpr42 = ((mu_HomeNode.mu_val) == (mu_LastWrite)) ; 
}
return mu__boolexpr42;
};

bool mu__condition_43() // Condition for Rule "value in memory matches value of last write, when invalid"
{
  return mu__invariant_41( );
}

/**** end rule declaration ****/

int mu__invariant_44() // Invariant "value in memory matches value of last write, when shared "
{
bool mu__boolexpr45;
  if (!((mu_HomeNode.mu_state) == (mu_H_Shared))) mu__boolexpr45 = TRUE ;
  else {
  mu__boolexpr45 = ((mu_HomeNode.mu_val) == (mu_LastWrite)) ; 
}
return mu__boolexpr45;
};

bool mu__condition_46() // Condition for Rule "value in memory matches value of last write, when shared "
{
  return mu__invariant_44( );
}

/**** end rule declaration ****/

int mu__invariant_47() // Invariant "Invalid implies empty owner"
{
bool mu__boolexpr48;
  if (!((mu_HomeNode.mu_state) == (mu_H_Invalid))) mu__boolexpr48 = TRUE ;
  else {
  mu__boolexpr48 = (mu_HomeNode.mu_owner.isundefined()) ; 
}
return mu__boolexpr48;
};

bool mu__condition_49() // Condition for Rule "Invalid implies empty owner"
{
  return mu__invariant_47( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Invalid implies empty owner", &mu__condition_49, NULL, FALSE},
{"value in memory matches value of last write, when shared ", &mu__condition_46, NULL, FALSE},
{"value in memory matches value of last write, when invalid", &mu__condition_43, NULL, FALSE},
{"values in modified state match last write", &mu__condition_40, NULL, FALSE},
{"value is undefined while invalid", &mu__condition_36, NULL, FALSE},
{"modified implies empty sharers list", &mu__condition_32, NULL, FALSE},
{"Invalid implies empty sharer list", &mu__condition_28, NULL, FALSE},
{"values in shared state match memory", &mu__condition_24, NULL, FALSE},
};
const unsigned short numinvariants = 8;

/******************/
bool mu__true_live() { return TRUE; }
/******************/

/********************
  Liveness records
 ********************/
const liverec livenesses[] = {
{ NULL, NULL, NULL, NULL, E }};
const unsigned short numlivenesses = 0;

/********************
  Fairstates records
 ********************/
const rulerec fairnesses[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numfairnesses = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
msg_processed:NoScalarset
LastWrite:NoScalarset
Procs:ScalarsetArrayOfFree
InBox:ScalarsetArrayOfScalarset
Net:Complex
HomeNode:Complex
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  int class_mu_1_Proc[2];
  int undefined_class_mu_1_Proc;// has the highest class number

  void Print_class_mu_1_Proc();
  bool OnlyOneRemain_mu_1_Proc;
  bool MTO_class_mu_1_Proc()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Proc)
      return FALSE;
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Proc = TRUE;
    return FALSE;
  }
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  int * in_mu_1_Proc;
  typedef int arr_mu_1_Proc[2];
  arr_mu_1_Proc * perm_mu_1_Proc;
  arr_mu_1_Proc * revperm_mu_1_Proc;

  int size_mu_1_Proc[2];
  bool reversed_sorted_mu_1_Proc(int start, int end);
  void reverse_reversed_mu_1_Proc(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_Proc* perm, int size, mu_1_Proc k);
  void GenPerm0(mu_1_Proc* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_Proc()
{
  cout << "class_mu_1_Proc:\t";
  for (int i=0; i<2; i++)
    cout << class_mu_1_Proc[i];
  cout << " " << undefined_class_mu_1_Proc << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_Proc Perm0[2];

  /********************
   declaration of class variables
  ********************/
  in = new bool[2];
 in_mu_1_Proc = new int[2];
 perm_mu_1_Proc = new arr_mu_1_Proc[2];
 revperm_mu_1_Proc = new arr_mu_1_Proc[2];

    // Set perm and revperm
    count = 0;
    for (i=1; i<=2; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=2)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<2; i++)
      for (j=1; j<=2; j++)
        for (k=1; k<=2; k++)
          if (revperm_mu_1_Proc[i][k-1]==j)   // k - base 
            perm_mu_1_Proc[i][j-1]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_Proc = 0;
    size = 2;
    count = 2;
    for (i=0; i<2; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_Proc[i] = i_mu_1_Proc;
      i_mu_1_Proc += carry;
      if (i_mu_1_Proc >= 2) { i_mu_1_Proc = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_Proc = new int[1];
 perm_mu_1_Proc = new arr_mu_1_Proc[1];
 revperm_mu_1_Proc = new arr_mu_1_Proc[1];
  in[0] = TRUE;
    in_mu_1_Proc[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<2; i++)
    class_mu_1_Proc[i]=0;
  undefined_class_mu_1_Proc=0;
  OnlyOneRemain_mu_1_Proc = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<2; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_Proc[2];
  int size_mu_1_Proc[2];
  bool should_be_in_mu_1_Proc[2];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	    start_mu_1_Proc[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<2; i++) // set up
    should_be_in_mu_1_Proc[i] = TRUE;
  for (i=0; i<2; i++) // to be in or not to be
    for (k=0; k<2; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Proc[i][k]-1 >=start_mu_1_Proc[k] 
	     && perm_mu_1_Proc[i][k]-1 < start_mu_1_Proc[k] + size_mu_1_Proc[k]) )
  	    {
	      should_be_in_mu_1_Proc[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<2; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_Proc[in_mu_1_Proc[i]]) in[i] = FALSE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Proc[k]==j)
	      revperm_mu_1_Proc[0][start++] = k+1;
    }
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_Proc[0][k]==j+1)
        perm_mu_1_Proc[0][j]=k+1;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_Proc* Perm, int size, mu_1_Proc k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_Proc* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=2)
    {
      for (i=1; i<=2; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=1; i<=2; i++)
        revperm_mu_1_Proc[count][i-1]=Perm[i-1].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_Proc(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Proc[0][i]<revperm_mu_1_Proc[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Proc(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Proc[0][j];
      revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][i];
      revperm_mu_1_Proc[0][i] = temp;
    }
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
  for (start = 0; start < 2; )
    {
      end = start-1+size_mu_1_Proc[revperm_mu_1_Proc[0][start]-1];
      if (reversed_sorted_mu_1_Proc(start,end))
	       {
	  reverse_reversed_mu_1_Proc(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Proc(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Proc[0][j]<revperm_mu_1_Proc[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Proc[0][j];
			  revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][k];
			  revperm_mu_1_Proc[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Proc(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) return FALSE;
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_Proc[0][k]==j+1)   // k - base 
	perm_mu_1_Proc[0][j]=k+1; // j - base 
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_msg_processed.MultisetSort();
        mu_LastWrite.MultisetSort();
        mu_Procs.MultisetSort();
        mu_InBox.MultisetSort();
        mu_Net.MultisetSort();
        mu_HomeNode.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_Proc::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-1]); // value - base
};
void mu_1_Proc::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
            Perm.class_mu_1_Proc[i]++;
        value(1 + Perm.undefined_class_mu_1_Proc++);
      }
    else 
      {
        value(Perm.class_mu_1_Proc[value()-1]+1);
      }
}
void mu_1_Proc::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Proc::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
            Perm.class_mu_1_Proc[i]++;
        Perm.undefined_class_mu_1_Proc++;
      }
}
void mu_1_Proc::ArrayLimit(PermSet& Perm) {}
void mu_1_Proc::Limit(PermSet& Perm) {}
void mu_1_Proc::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Value::Permute(PermSet& Perm, int i) {}
void mu_1_Value::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_Value::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Value::SimpleLimit(PermSet& Perm) {}
void mu_1_Value::ArrayLimit(PermSet& Perm) {}
void mu_1_Value::Limit(PermSet& Perm) {}
void mu_1_Value::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Home::Permute(PermSet& Perm, int i) {};
void mu_1_Home::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Home::Canonicalize(PermSet& Perm) {};
void mu_1_Home::SimpleLimit(PermSet& Perm) {};
void mu_1_Home::ArrayLimit(PermSet& Perm) {};
void mu_1_Home::Limit(PermSet& Perm) {};
void mu_1_Home::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Node::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 2 ) )
      value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-1]+(0)); // value - base
  }
}
void mu_1_Node::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 2 ) )
      {
        if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<2; i++)
              if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
                Perm.class_mu_1_Proc[i]++;
            value(1 + Perm.undefined_class_mu_1_Proc++);
          }
        else 
          {
            value(Perm.class_mu_1_Proc[value()-1]+1);
          }
      }
  }
}
void mu_1_Node::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Node::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 2 ) )
      if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<2; i++)
            if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
              Perm.class_mu_1_Proc[i]++;
          Perm.undefined_class_mu_1_Proc++;
        }
  }
}
void mu_1_Node::ArrayLimit(PermSet& Perm) {}
void mu_1_Node::Limit(PermSet& Perm) {}
void mu_1_Node::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_VCType::Permute(PermSet& Perm, int i) {};
void mu_1_VCType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_VCType::Canonicalize(PermSet& Perm) {};
void mu_1_VCType::SimpleLimit(PermSet& Perm) {};
void mu_1_VCType::ArrayLimit(PermSet& Perm) {};
void mu_1_VCType::Limit(PermSet& Perm) {};
void mu_1_VCType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_AckType::Permute(PermSet& Perm, int i) {};
void mu_1_AckType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_AckType::Canonicalize(PermSet& Perm) {};
void mu_1_AckType::SimpleLimit(PermSet& Perm) {};
void mu_1_AckType::ArrayLimit(PermSet& Perm) {};
void mu_1_AckType::Limit(PermSet& Perm) {};
void mu_1_AckType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_MessageType::Permute(PermSet& Perm, int i) {};
void mu_1_MessageType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MessageType::Canonicalize(PermSet& Perm) {};
void mu_1_MessageType::SimpleLimit(PermSet& Perm) {};
void mu_1_MessageType::ArrayLimit(PermSet& Perm) {};
void mu_1_MessageType::Limit(PermSet& Perm) {};
void mu_1_MessageType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Message::Permute(PermSet& Perm, int i)
{
  mu_src.Permute(Perm,i);
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_src.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_src.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Node value[2];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[2][2];
  bool goodset_mu_1_Proc[2];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[2][2];
  bool goodset_multisetindex[2];
  mu_1_Node temp;

  // compact
  for (i = 0, j = 0; i < 2; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 2; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 2; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<2);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_Proc = count_mu_1_Proc;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].isundefined())
                && (*this)[k]>=1
                && (*this)[k]<=2)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Proc; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].isundefined()
                          && (*this)[k]>=1
                          && (*this)[k]<=2
                          && pos_mu_1_Proc[j][(*this)[k]-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Proc[(*this)[k]-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j][k] = FALSE;
                                if (pos_mu_1_Proc[j+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_Proc<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  }
}
void mu_1_HomeState::Permute(PermSet& Perm, int i)
{
  mu_owner.Permute(Perm,i);
  mu_sharers.Permute(Perm,i);
};
void mu_1_HomeState::SimpleCanonicalize(PermSet& Perm)
{
  mu_owner.SimpleCanonicalize(Perm);
};
void mu_1_HomeState::Canonicalize(PermSet& Perm)
{
};
void mu_1_HomeState::SimpleLimit(PermSet& Perm)
{
  mu_owner.SimpleLimit(Perm);
};
void mu_1_HomeState::ArrayLimit(PermSet& Perm){}
void mu_1_HomeState::Limit(PermSet& Perm)
{
  mu_sharers.Limit(Perm);
};
void mu_1_HomeState::MultisetLimit(PermSet& Perm)
{
  mu_sharers.MultisetLimit(Perm);
};
void mu_1__type_2::Permute(PermSet& Perm, int i) {};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_2::Canonicalize(PermSet& Perm) {};
void mu_1__type_2::SimpleLimit(PermSet& Perm) {};
void mu_1__type_2::ArrayLimit(PermSet& Perm) {};
void mu_1__type_2::Limit(PermSet& Perm) {};
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_ProcState::Permute(PermSet& Perm, int i)
{
};
void mu_1_ProcState::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_ProcState::Canonicalize(PermSet& Perm)
{
};
void mu_1_ProcState::SimpleLimit(PermSet& Perm){}
void mu_1_ProcState::ArrayLimit(PermSet& Perm){}
void mu_1_ProcState::Limit(PermSet& Perm)
{
};
void mu_1_ProcState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=2; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_3::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Proc;
  int compare;
  static mu_1_ProcState value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Proc[2];
  bool pos_mu_1_Proc[2][2];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_Proc[2];
  int start_mu_1_Proc[2];
  // canonicalization
  static mu_1__type_3 temp;
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<2; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<2; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<2; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_Proc())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_Proc; j++) // class number
        {
          class_size = 0;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_Proc[k]==j)
              class_size++;
          for (k=0; k<2; k++) // step through class[k]
            if (Perm.class_mu_1_Proc[k]==j)
              {
                size_mu_1_Proc[k] = class_size;
                start_mu_1_Proc[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
         if (i >=start_mu_1_Proc[j] 
             && i < start_mu_1_Proc[j] + size_mu_1_Proc[j])
           {
             array[i+0] = temp[j+1];
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<2; j++)
        array[Perm.class_mu_1_Proc[j]+0] = temp[j+1];
    }
}
void mu_1__type_3::SimpleLimit(PermSet& Perm){}
void mu_1__type_3::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Proc;
  int compare;
  static mu_1_ProcState value[2];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Proc[2];
  bool pos_mu_1_Proc[2][2];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<2; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<2; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<2; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_3::Limit(PermSet& Perm){}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
  static mu_1__type_4 temp("Permute_mu_1__type_4",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_4::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Message value[4];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[2][2];
  bool goodset_mu_1_Proc[2];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[4][4];
  bool goodset_multisetindex[4];
  mu_1_Message temp;

  // compact
  for (i = 0, j = 0; i < 4; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 4; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 4; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<2);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_Proc = count_mu_1_Proc;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_src.isundefined())
                && (*this)[k].mu_src>=1
                && (*this)[k].mu_src<=2)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Proc; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_src.isundefined()
                          && (*this)[k].mu_src>=1
                          && (*this)[k].mu_src<=2
                          && pos_mu_1_Proc[j][(*this)[k].mu_src-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Proc[(*this)[k].mu_src-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j][k] = FALSE;
                                if (pos_mu_1_Proc[j+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_Proc<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  }
}
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=2; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];
};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm){};
void mu_1__type_5::SimpleLimit(PermSet& Perm){}
void mu_1__type_5::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_4 value[3];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Proc;
  bool pos_mu_1_Proc[2][2];
  bool goodset_mu_1_Proc[2];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<2; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<2; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<2; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_5::Limit(PermSet& Perm){}
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_6::Permute(PermSet& Perm, int i)
{
  static mu_1__type_6 temp("Permute_mu_1__type_6",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<3; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_6::Canonicalize(PermSet& Perm){};
void mu_1__type_6::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<3; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_6::ArrayLimit(PermSet& Perm) {}
void mu_1__type_6::Limit(PermSet& Perm){}
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_7::Permute(PermSet& Perm, int i)
{
  static mu_1__type_7 temp("Permute_mu_1__type_7",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=2; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];
};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_7::Canonicalize(PermSet& Perm){};
void mu_1__type_7::SimpleLimit(PermSet& Perm){}
void mu_1__type_7::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_6 value[3];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Proc;
  bool pos_mu_1_Proc[2][2];
  bool goodset_mu_1_Proc[2];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<2; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<2; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<2; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<2; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<2; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<2; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_7::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1__type_6 value[3];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[2][2];
  bool goodset_mu_1_Proc[2];
  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<2)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<2; k++) // step through class
        if ((*this)[k+1][i0].mu_src.isundefined()
            ||(*this)[k+1][i0].mu_src!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<2; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<2; k++) // step through class
                if (pos_mu_1_Proc[i][k] 
                    && !(*this)[k+1][i0].mu_src.isundefined()
                    && (*this)[k+1][i0].mu_src==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<2; k++)
                    if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Proc; j>i; j--)
                        for (k=0; k<2; k++)
                          pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                      for (k=0; k<2; k++)
                        {
                          if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i][k] = FALSE;
                          if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i+1][k] = FALSE;
                        }
                      count_mu_1_Proc++; i++;
                    }
                }
            }
        }
    }
  }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<2);
  while ( while_guard )
    {
      oldcount_mu_1_Proc = count_mu_1_Proc;
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<2)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<2; k++) // step through class
            if (!(*this)[k+1][i0].mu_src.isundefined()
                &&(*this)[k+1][i0].mu_src!=k+1
                &&(*this)[k+1][i0].mu_src>=1
                &&(*this)[k+1][i0].mu_src<=2)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Proc; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Proc; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<2; k++) // step through class
                        goodset_mu_1_Proc[k] = FALSE;
                      for (k=0; k<2; k++) // step through class
                        if (pos_mu_1_Proc[i][k] 
                            && !(*this)[k+1][i0].mu_src.isundefined()
                            && (*this)[k+1][i0].mu_src!=k+1
                            && (*this)[k+1][i0].mu_src>=1
                            && (*this)[k+1][i0].mu_src<=2
                            && pos_mu_1_Proc[j][(*this)[k+1][i0].mu_src-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_Proc[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<2; k++)
                            if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Proc; j>i; j--)
                                for (k=0; k<2; k++)
                                  pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                              for (k=0; k<2; k++)
                                {
                                  if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i][k] = FALSE;
                                  if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Proc++;
                            }
                        }
                    }
                }
            }
        }
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {
  }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_Proc<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
}
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_8::Permute(PermSet& Perm, int i) {};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_8::Canonicalize(PermSet& Perm) {};
void mu_1__type_8::SimpleLimit(PermSet& Perm) {};
void mu_1__type_8::ArrayLimit(PermSet& Perm) {};
void mu_1__type_8::Limit(PermSet& Perm) {};
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_msg_processed.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_LastWrite.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_LastWrite.MultisetSort();
              mu_Procs.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
              mu_InBox.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_InBox.MultisetSort();
              mu_Net.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
              mu_HomeNode.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_HomeNode.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_msg_processed.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_msg_processed.MultisetSort();
          mu_LastWrite.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_LastWrite.MultisetSort();
          mu_Procs.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Procs.MultisetSort();
          mu_InBox.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_InBox.MultisetSort();
          mu_Net.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Net.MultisetSort();
          mu_HomeNode.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_HomeNode.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_msg_processed.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_LastWrite.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_LastWrite.MultisetSort();
              mu_Procs.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
              mu_InBox.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_InBox.MultisetSort();
              mu_Net.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
              mu_HomeNode.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_HomeNode.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_msg_processed.MultisetSort();
      mu_LastWrite.MultisetSort();
      mu_Procs.MultisetSort();
      mu_InBox.MultisetSort();
      mu_Net.MultisetSort();
      mu_HomeNode.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_msg_processed.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_msg_processed.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_LastWrite.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_LastWrite.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Procs.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Procs.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_InBox.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_InBox.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_HomeNode.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_HomeNode.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_Procs.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNode.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNode.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_InBox.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_InBox.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_HomeNode.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_HomeNode.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_Procs.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNode.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNode.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_InBox.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_InBox.MultisetSort();
  mu_Net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Net.MultisetSort();
  mu_HomeNode.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_HomeNode.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_InBox.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_InBox.MultisetSort();
      mu_Net.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_Net.MultisetSort();
      mu_HomeNode.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_HomeNode.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_Procs.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNode.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_InBox.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_InBox.MultisetSort();

  mu_Net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Net.MultisetSort();

  mu_HomeNode.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_HomeNode.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"

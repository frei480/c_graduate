
;; Function print_conv (print_conv, funcdef_no=40, decl_uid=3195, cgraph_uid=41, symbol_order=40)

void print_conv (unsigned int x, unsigned int y)
{
  int k;
  unsigned int num[32];
  unsigned int _1;
  unsigned int _2;

  <bb 2> [local count: 118111600]:
  num = {};
  if (x_11(D) != 0)
    goto <bb 3>; [89.00%]
  else
    goto <bb 4>; [11.00%]

  <bb 3> [local count: 955630225]:
  # x_24 = PHI <x_17(3), x_11(D)(2)>
  # k_25 = PHI <k_18(3), 0(2)>
  _1 = x_24 % y_15(D);
  num[k_25] = _1;
  x_17 = x_24 / y_15(D);
  k_18 = k_25 + 1;
  if (x_17 != 0)
    goto <bb 3>; [89.00%]
  else
    goto <bb 4>; [11.00%]

  <bb 4> [local count: 118111600]:
  # k_26 = PHI <k_18(3), 0(2)>
  k_12 = k_26 + -1;
  if (k_12 != -1)
    goto <bb 5>; [89.00%]
  else
    goto <bb 6>; [11.00%]

  <bb 5> [local count: 955630225]:
  # k_27 = PHI <k_14(5), k_12(4)>
  k_14 = k_27 + -1;
  _2 = num[k_27];
  __printf_chk (1, "%u", _2);
  if (k_14 != -1)
    goto <bb 5>; [89.00%]
  else
    goto <bb 6>; [11.00%]

  <bb 6> [local count: 118111600]:
  num ={v} {CLOBBER};
  return;

}



;; Function main (main, funcdef_no=39, decl_uid=3196, cgraph_uid=40, symbol_order=39) (executed once)

int main ()
{
  static const char __PRETTY_FUNCTION__[5] = "main";
  int res;
  unsigned int y;
  unsigned int x;
  unsigned int y.0_1;
  unsigned int x.1_2;

  <bb 2> [local count: 1073741824]:
  res_5 = scanf ("%u%u", &x, &y);
  if (res_5 == 2)
    goto <bb 4>; [99.96%]
  else
    goto <bb 3>; [0.04%]

  <bb 3> [local count: 429496]:
  __assert_fail ("res==2", "ns.c", 13, &__PRETTY_FUNCTION__);

  <bb 4> [local count: 1073312329]:
  y.0_1 = y;
  x.1_2 = x;
  print_conv (x.1_2, y.0_1);
  x ={v} {CLOBBER};
  y ={v} {CLOBBER};
  return 0;

}




;; Function main (main, funcdef_no=39, decl_uid=3196, cgraph_uid=40, symbol_order=39)

int main ()
{
  static const char __PRETTY_FUNCTION__[5] = "main";
  int res;
  unsigned int y;
  unsigned int x;
  int D.3218;

  res = scanf ("%u%u", &x, &y);
  if (res == 2) goto <D.3215>; else goto <D.3216>;
  <D.3215>:
  goto <D.3217>;
  <D.3216>:
  __assert_fail ("res==2", "ns.c", 13, &__PRETTY_FUNCTION__);
  <D.3217>:
  y.0_1 = y;
  x.1_2 = x;
  print_conv (x.1_2, y.0_1);
  D.3218 = 0;
  goto <D.3220>;
  <D.3220>:
  x = {CLOBBER};
  y = {CLOBBER};
  goto <D.3219>;
  D.3218 = 0;
  goto <D.3219>;
  <D.3219>:
  return D.3218;
}



;; Function print_conv (print_conv, funcdef_no=40, decl_uid=3195, cgraph_uid=41, symbol_order=40)

void print_conv (unsigned int x, unsigned int y)
{
  int k;
  unsigned int num[32];

  num = {};
  k = 0;
  goto <D.3209>;
  <D.3210>:
  _1 = x % y;
  num[k] = _1;
  x = x / y;
  k = k + 1;
  <D.3209>:
  if (x != 0) goto <D.3210>; else goto <D.3208>;
  <D.3208>:
  k = k + -1;
  goto <D.3212>;
  <D.3213>:
  k.2_2 = k;
  k = k.2_2 + -1;
  _3 = num[k.2_2];
  printf ("%u", _3);
  <D.3212>:
  if (k >= 0) goto <D.3213>; else goto <D.3211>;
  <D.3211>:
  num = {CLOBBER};
  return;
}



;; Function printf (<unset-asm-name>, funcdef_no=15, decl_uid=964, cgraph_uid=16, symbol_order=15)

__attribute__((artificial, gnu_inline, always_inline))
__attribute__((nonnull (1), format (printf, 1, 2)))
int printf (const char * restrict __fmt)
{
  int D.3221;

  D.3221 = __printf_chk (1, __fmt, __builtin_va_arg_pack ());
  goto <D.3222>;
  <D.3222>:
  return D.3221;
}



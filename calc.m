//Taylor Morrow
//Instructions for HP15c

define(loc, 0)
define(g, 43)
define(f, 42)
define(x_r, 0)

define(div, `10 define(`loc', eval(loc + 1))')
define(mul, `20 define(`loc', eval(loc + 1))')
define(sub, `30 define(`loc', eval(loc + 1))')
define(add, `40 define(`loc', eval(loc + 1))')
define(ent, `36 define(`loc', eval(loc + 1))')
define(sto, `44 $1 define(`loc', eval(loc + 2))')
define(rcl, `45 $1 define(`loc', eval(loc + 2))')
define(rtn, `g 32 define(`loc', eval(loc + 2))')
define(pse, `f 31 define(`loc', eval(loc + 1))')
define(digit, `$1 define(`loc', eval(loc + 1))')

digit(9)
ent
sto(x_r)
digit(1)
sub
rcl(x_r)
digit(7)
sub
mul
rcl(x_r)
digit(1)
digit(1)
ent
sub
div
pse
rtn
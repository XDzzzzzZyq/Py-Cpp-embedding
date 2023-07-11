import sys, os
pth = os.path.dirname(os.getcwd()) + r"\Build_x64"

sys.path.append(pth)

import TestModule as tmd

a = tmd.Test(3, 4)
a.info()
tmd.Test.print()

tmd.info()
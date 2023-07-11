import sys, os
pth = os.path.dirname(os.getcwd()) + r"\Build_x64"

sys.path.append(pth)

import TestModule as tmd
tmd.info()

a = tmd.Test(3, 4)
a.info()

UI = tmd.UI()

UI.init()
tmd.UI.info()

while UI.is_window_open():
    UI.new_frame()
    UI.render()

UI.terminate()
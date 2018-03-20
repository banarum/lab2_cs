import os
import random

cmds = ["pop_top", "push"]

dir = os.path.dirname(os.path.abspath(__file__))


def get_random_cmd():
    cmd = random.choice(cmds)
    if (cmd == "push"):
        num = random.randint(10, 100000)
    else:
        num = 0
    return cmd + " " + str(num)

def gen_cmds_to(path):
    max_cmds = 10000
    f = open(dir + "\\"+path, "w")
    rStr = ""
    for i in range(max_cmds):
        cmd = get_random_cmd()
        rStr+=cmd+"\n"

    f.write(rStr)
    f.close()

gen_cmds_to("cmds_part_1.in")
gen_cmds_to("cmds_part_2.in")
gen_cmds_to("cmds_part_3.in")
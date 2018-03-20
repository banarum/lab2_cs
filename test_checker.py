import os

dir = os.path.dirname(os.path.abspath(__file__))

def exec_cmd(stack, cmd, prm):
    if cmd == "push":
        stack.append(prm)
        return None
    if cmd == "pop_top":
        if len(stack) > 0:
            return stack.pop()
        return None


def check_test(filename):
    stack = []
    fr = open(dir + "\\" + filename + ".in", "r")
    fw = open(dir + "\\" + filename + ".out", "r")
    results = []
    index = 0
    for line in fr:
        cmd = line.split(" ")[0]
        prm = int(line.split(" ")[1])
        result = exec_cmd(stack, cmd, prm)
        if result:
            results.append(result)

    trigger = True

    for line in fw:
        answer = int(line)
        if len(results) <= index:
            print("Wrong length (more)")
            trigger = False
            continue
        elif results[index] != answer:
            print("Wrong answer ", str(results[index])+" AND "+str(answer))
            trigger = False
            index += 1
            continue
        index += 1

    if index != len(results):
        print("Wrong length")
        trigger = False

    fw.close()
    fr.close()

    return trigger


print(check_test("cmds_part_1"))
print(check_test("cmds_part_2"))
print(check_test("cmds_part_3"))

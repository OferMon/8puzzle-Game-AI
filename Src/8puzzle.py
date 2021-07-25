import copy

def init_state():
    file_handler = open('puzzleInitState.txt', 'r')
    file_lines = file_handler.readlines()
    state = [line.split() for line in file_lines]
    return state

def goal_state(state):
    flat_list = [item for sublist in state for item in sublist]
    for i in range(len(flat_list)):
        if i != int(flat_list[i]):
            return False
    return True

def get_successors(state):
    position = get_zero_index(state)
    list_of_successors = []
    # Up
    if position[0] != 0:
        list_of_successors.append(('up', replace_state(state, position, (position[0] - 1, position[1]))))
    # down
    if position[0] != len(state) - 1:
        list_of_successors.append(('down', replace_state(state, position, (position[0] + 1, position[1]))))
    # left
    if position[1] != 0:
        list_of_successors.append(('left', replace_state(state, position, (position[0], position[1] - 1))))
    # right
    if position[1] != len(state) - 1:
        list_of_successors.append(('right', replace_state(state, position, (position[0], position[1] + 1))))
    return list_of_successors

def replace_state(state, zero_index, target_index):
    new_state = copy.deepcopy(state)
    new_state[zero_index[0]][zero_index[1]] = new_state[target_index[0]][target_index[1]]
    new_state[target_index[0]][target_index[1]] = '0'
    return new_state

def get_zero_index(state):
    for r in range(len(state)):
        for c in range(len(state)):
            if state[r][c] == '0':
                return (r, c)
    return (-1, -1)

def misplaced_h(state):
    flat_list = [item for sublist in state for item in sublist]
    count = 0
    for i in range(len(flat_list)):
        if i != int(flat_list[i]):
            count += 1
    return count

def md_h(state):
    sum = 0
    for r in range(len(state)):
        for c in range(len(state)):
            sum += abs(r - int(int(state[r][c]) / len(state))) + abs(c - int(state[r][c]) % len(state))
    return sum

def greedy_best_first(state, h):
    open = [(state, None, h(state), None)]
    close = []
    while len(open) != 0:
        open.sort(reverse = True, key = get_h)
        next = open.pop()
        close.append(next)
        if goal_state(next[0]):
            print_path(next)
            print(f'Number of opened nodes: {len(close)}\n')
            return True
        for s in get_successors(next[0]):
            tempNode = check_state_in_list(s[1], open, close)
            if tempNode == False:
                new = (s[1], next, h(s[1]), s[0])
                open.append(new)
    print('There is no solution!\n')
    return False

def astar(state, h):
    open = [(state, None, h(state), None, 0)]
    close = []
    while len(open) != 0:
        open.sort(reverse = True, key = get_f)
        next = open.pop()
        close.append(next)
        if goal_state(next[0]):
            print_path(next)
            print(f'Number of opened nodes: {len(close)}\n')
            return True
        for s in get_successors(next[0]):
            tempNode = check_state_in_list(s[1], open, close)
            if tempNode == False:
                new = (s[1], next, h(s[1]), s[0], next[4] + 1)
                open.append(new)
            elif tempNode[4] > (next[4] + 1):
                tempNode = (tempNode[0], next, tempNode[2], tempNode[3], next[4] + 1)
                try:
                    open.remove(tempNode)
                except:
                    pass
                try:
                    close.remove(tempNode)
                except:
                    pass
                open.append(tempNode)
    print('There is no solution!\n')
    return False

def print_path(state):
    moves = []
    while state[1] != None:
        moves.append(state[3])
        state = state[1]
    print(f'Moves: {str(moves[::-1])}')

def check_state_in_list(state, nodesList, nodesList2):
    for i in nodesList:
        if compare_state(state, i[0]):
            return i
    for i in nodesList2:
        if compare_state(state, i[0]):
            return i
    return False

def compare_state(state1, state2):
    flat_list1 = [item for sublist in state1 for item in sublist]
    flat_list2 = [item for sublist in state2 for item in sublist]
    for i in range(len(flat_list1)):
        if int(flat_list1[i]) != int(flat_list2[i]):
            return False
    return True

def get_h(node):
    return node[2]

def get_f(node):
    return node[2] + node[4]

l = init_state()
print('GBF using Manhattan distance:')
greedy_best_first(l, md_h)

print('GBF using misplaced nodes:')
greedy_best_first(l, misplaced_h)

print('Astar using Manhattan distance:')
astar(l, md_h)

print('Astar using misplaced nodes:')
astar(l, misplaced_h)
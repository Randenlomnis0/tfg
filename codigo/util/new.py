from check_integrity import load_info
import random

def get_new(judg, lan):
    info = load_info()

    options = list()

    for judge, problem, lang in info:
        if judge != judg:
            continue

        if lang != lan:
            continue

        if info[(judge, problem, lang)] != 'NV':
            continue

        options.append(problem)
    if len(options) == 0:
        return 'THERE ARE NO NEW PROBLEMS'
    
    return random.choice(options)

def main():
    lan = 'cpp'

    print(f'lan={lan} -> \033[1m{get_new('kat', lan)}\033[0m')

if __name__ == '__main__':
    main()
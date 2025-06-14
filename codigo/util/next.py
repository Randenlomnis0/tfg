from check_integrity import load_info
from settings import lan

def get_next(judg, lan):
    info = load_info()

    for judge, _, problem, lang in info:
        if judge != judg:
            continue

        if lang != lan:
            continue

        if info[(judge, problem, lang)] != 'NC':
            continue

        return problem
    
    return 'THERE IS NO NEXT PROBLEM'

def main():
    print(f'lan={lan} -> \033[1m{get_next('kat', lan)}\033[0m')

if __name__ == '__main__':
    main()
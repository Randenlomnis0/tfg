from check_integrity import load_info

def load_stats():
    info = load_info()

    stats = dict()

    for (_, _, _, lan), veredict in info.items():
        if lan not in stats:
            stats[lan] = dict()

        if veredict not in stats[lan]:
            stats[lan][veredict] = 0

        stats[lan][veredict] += 1

    return stats

def print_stats(stats):
    for lan in stats:
        lan_total = 0

        for _, cnt in stats[lan].items():
            lan_total += cnt

        aux = f'{lan}\t->'

        for veredict, cnt in stats[lan].items():
            aux += f'\t\033[1m{veredict}=\033[0m{cnt}(\033[1m{100 * cnt / lan_total:.2f}\033[0m%)'

        print(aux)

def main():
    stats = load_stats()

    print_stats(stats)

if __name__ == '__main__':
    main()
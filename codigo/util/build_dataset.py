import csv
import os
from pathlib import Path
import re
import statistics

from check_integrity import load_archivos, load_info
from settings import folder_soluciones

def load_data() -> dict:
    all_data = load_info()

    selected_data = []

    for (plat, cat, name, lan), v in all_data.items():
        valid = True

        for l in ['cpp', 'py', 'java']:
            if all_data[(plat, cat, name, l)] == 'AC':
                continue

            valid = False

        if not valid:
            continue

        selected_data.append([plat, cat, name, lan])

    for data in selected_data:
        file_name = Path(f"{data[2]}.{data[3]}")
        file_path = folder_soluciones / Path(plat) / file_name

        data.append(os.path.getsize(file_path))
        
        with open(file_path, mode='r', encoding='utf-8') as file:
            content = file.read()

        data.append(len(content))

        data.append(len(re.sub(r'\s+', '', content)))

        data.append(content.count('\n'))

        tokens = content.split()

        data.append(len(tokens))

        data.append(sum(len(token) for token in tokens) / len(tokens))

        data.append(statistics.stdev(len(token) for token in tokens))

    fields = [['Platform', 'Category', 'Name', 'Language', 'Size', 'Characters', 'NonWhitespaceCharacters', 'Lines', 'Tokens', 'AverageTokenLength', 'SDTokenLength']]

    return fields + selected_data

def main():
    data = load_data()

    with open('tfg.csv', mode='w', newline='', encoding='utf-8') as file:
        writer = csv.writer(file, quoting=csv.QUOTE_MINIMAL)
        writer.writerows(data)

if __name__ == '__main__':
    main()

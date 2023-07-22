import json
import requests
import sys

# 获取数字范围
def get_numbers():
    # 检查命令行参数是否传递
    if len(sys.argv) > 1:
        # 提取命令行参数并转换为整数列表
        numbers = list(map(int, sys.argv[1:]))
    else:
        # 默认范围为 0 到 1
        numbers = list(range(0, 2))

    return numbers

def get_file_name(numbers):
    min_number = min(numbers)
    max_number = max(numbers)
    return f"{min_number}-{max_number}_urls.txt"

def download_urls(numbers):
    headers = {
        'authority': 'phenaid.ardigen.com',
        'accept': 'application/json, text/plain, */*',
        'accept-language': 'zh-CN,zh;q=0.9',
        'cookie': '_gcl_au=1.1.423162906.1689325031; _ga=GA1.1.479542853.1689325031; ln_or=eyIzODQzOTk0IjoiZCJ9; __hstc=95507139.d67872d0b23d3b8a41fe8fee5b1dbb2f.1689325044697.1689325044697.1689325044697.1; hubspotutk=d67872d0b23d3b8a41fe8fee5b1dbb2f; __hssrc=1; _fbp=fb.1.1689325048920.58393134; _ga_CCN9ZW80L8=GS1.1.1689325031.1.1.1689326048.0.0.0; __hssc=95507139.4.1689325044698',
        'referer': 'https://phenaid.ardigen.com/jumpcpexplorer/',
        'sec-ch-ua': '"Not.A/Brand";v="8", "Chromium";v="114", "Google Chrome";v="114"',
        'sec-ch-ua-mobile': '?0',
        'sec-ch-ua-platform': '"macOS"',
        'sec-fetch-dest': 'empty',
        'sec-fetch-mode': 'cors',
        'sec-fetch-site': 'same-origin',
        'user-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36'
    }

    file_name = get_file_name(numbers)

    with open(file_name, 'a') as f:
        for number in numbers:
            url = f'https://phenaid.ardigen.com/api-jumpcpexplorer/compound-info/{number}'

            response = requests.get(url, headers=headers)
            data = response.json()

            folder = str(number)
            for image_url in data['compound_info']['images']:
                parts = image_url.split('/')
                filename = f"{parts[-3]}-{parts[-2]}-{parts[-1]}"
                f.write(f'{folder}::Images for {folder}::{filename}::{image_url}\n')

            for control_image_url in data['compound_info']['control_images']:
                parts = control_image_url.split('/')
                filename = f"{parts[-3]}-{parts[-2]}-{parts[-1]}"
                f.write(f'{folder}::Control Images for {folder}::{filename}::{control_image_url}\n')

def main():
    download_urls(get_numbers())

if __name__ == "__main__":
    main()
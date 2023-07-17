import json
import requests

# 创建一个范围从0到115793的数字列表
# numbers = list(range(0, 115794))
numbers = list(range(0, 2))

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

for number in numbers:
    url = f'https://phenaid.ardigen.com/api-jumpcpexplorer/compound-info/{number}'
    
    response = requests.get(url, headers=headers)
    data = response.json()

    with open('image_urls.txt', 'a') as f:  # 使用 'a' 模式以追加的方式写入文件
        f.write(f'Images for {number}:\n')
        for image_url in data['compound_info']['images']:
            f.write(image_url + '\n')

        f.write(f'\nControl Images for {number}:\n')
        for control_image_url in data['compound_info']['control_images']:
            f.write(control_image_url + '\n')
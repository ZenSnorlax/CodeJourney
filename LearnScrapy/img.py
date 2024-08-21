import requests
import re

# 设置请求头
headers = {
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/127.0.0.0 Safari/537.36"
}


def down_img(url: str):
    response = requests.get(url, headers=headers)

    # 将内容转换为字符串
    content = response.content.decode("utf-8")

    # 使用正则表达式查找所有的 img 标签中的 src 属性
    pattern = r'<img\sclass[^>]+src="([^"]+)"'
    matches = re.findall(pattern, content)

    if not matches:
            print(f"页面 {url} 没有图片")
            return
    
    # 打印并保存图片
    for match in matches:
        # 检查 URL 是否已经包含了协议
        if not match.startswith("http"):
            full_url = f"https:{match}"
        else:
            full_url = match

        print(f"Image URL: {full_url}")

        # 下载并保存图片
        try:
            image_response = requests.get(full_url)
            image_name = match.split("/")[-1]

            with open(image_name, "wb") as img_file:
                img_file.write(image_response.content)
        except requests.exceptions.RequestException as e:
            print(f"Failed to download {full_url}: {e}")


start = "5078804"
for i in range(0, 100):
    current_url = f"https://www.nipic.com/show/{int(start) + i}.html"
    down_img(current_url)

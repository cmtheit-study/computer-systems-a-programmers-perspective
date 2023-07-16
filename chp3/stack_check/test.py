import subprocess
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

results = []

for _ in range(1000):
    output = subprocess.check_output(['./main'])  # 替换成实际的可执行文件名称
    address = int(output.decode().strip(), 16)
    results.append(address)

# 自定义格式化函数，将整数转换为16进制字符串
def format_hex(x, pos):
    return f'0x{int(x):X}'

plt.hist(results, bins=30, edgecolor='black')
plt.xlabel('Memory Address')
plt.ylabel('Frequency')
plt.title('Distribution of Memory Addresses')

# 使用自定义的格式化函数设置x轴刻度格式
ax = plt.gca()
ax.xaxis.set_major_formatter(ticker.FuncFormatter(format_hex))

plt.show()

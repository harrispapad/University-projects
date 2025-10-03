import pandas as pd
import matplotlib.pyplot as plt
import re

df = pd.read_csv('vmean_sweep.csv')

pattern = re.compile(r'VM=([\d.e-]+)')
vmean_values = sorted({m.group(1) for col in df.columns for m in [pattern.search(col)] if m}, key=float)

fig, ax = plt.subplots(figsize=(10, 7))

for v in vmean_values:
    x_col = f'Iout (VM={v}) X'
    y_col = f'Iout (VM={v}) Y'
    label_text = f'VM = {float(v) * 1000:.0f}mV'
    
    ax.plot(df[x_col], df[y_col] * 1e9, label=label_text)

ax.set_xlabel('$V_{in}$ (V)', fontsize=14)
ax.set_ylabel('$I_{out}$ (nA)', fontsize=14)
ax.grid(True, which='both', linestyle='--', linewidth=0.5)

ax.set_ylim(bottom=0, top=16) 

ax.legend(fontsize=18, loc='upper right')

plt.tight_layout()
plt.show()
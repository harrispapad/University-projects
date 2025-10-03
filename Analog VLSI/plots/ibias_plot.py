import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.ticker as mticker
import re

df = pd.read_csv('ibias_sweep.csv')

pattern = re.compile(r'IBIAS=([\d.e-]+)')
ibias_values = sorted({m.group(1) for col in df.columns for m in [pattern.search(col)] if m})

fig, ax = plt.subplots(figsize=(10, 7))

for ibias in ibias_values:
    x_col = f'Iout (IBIAS={ibias}) X'
    y_col = f'Iout (IBIAS={ibias}) Y'
    label_text = f'IBIAS = {1e9*float(ibias):.0f}nA'
    ax.plot(df[x_col], df[y_col], label=label_text)

ax.set_xlabel('$V_{in}$ (V)', fontsize=12)
ax.set_ylabel('$I_{out}$ (nA)', fontsize=12)
ax.grid(True, which='both', linestyle='--', linewidth=0.5)

ax.yaxis.set_major_locator(mticker.MultipleLocator(5e-9))

ax.yaxis.set_major_formatter(mticker.FuncFormatter(lambda y, _: f'{y*1e9:.0f}'))

ax.set_ylim(0, 30e-9)
ax.legend(fontsize=18)

plt.tight_layout()
plt.show()
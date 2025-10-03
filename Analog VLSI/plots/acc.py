import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_excel('20_iterations_final.xlsx', skipfooter=1, engine='openpyxl')

fig, ax = plt.subplots(figsize=(10, 7))

bins = np.arange(0.7, 1.01, 0.025)

ax.hist([df['Hardware'], df['Software']],
        label=['Hardware', 'Software'],
        color=['#4C72B0', '#DD8452']) 

ax.set_title('Bayesian Classifier Comparison', fontsize=30)
ax.set_xlabel('Classification Accuracy', fontsize=25)
ax.set_ylabel('No of Iterations', fontsize=25)
ax.legend(fontsize=20)

ax.grid(axis='y', linestyle='--', linewidth=0.5)

ax.set_xticks(bins)
plt.xticks(rotation=30, ha='right')

plt.tight_layout()
plt.show()
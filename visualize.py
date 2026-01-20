import matplotlib.pyplot as plt
import csv


bst_data = {}
treap_data = {}

with open('reddit_performance_results.csv', 'r') as file:
    reader = csv.DictReader(file)
    for row in reader:
        metric = row['Metric']
        bst_data[metric] = float(row['BST'])
        treap_data[metric] = float(row['Treap'])

# Get data size for title
data_size = int(bst_data.get('Data Size', 100000))

# Create figure with 2x3 subplots
fig, axes = plt.subplots(2, 3, figsize=(15, 10))
fig.suptitle(f'BST vs Treap Performance Comparison ({data_size:,} Posts)', fontsize=14, fontweight='bold')

# Graph 1: Time Comparison (Bar Chart)
metrics = ['Insert Time (ms)', 'Search Time (ms)', 'Delete Time (ms)']
bst_times = [bst_data[m] for m in metrics]
treap_times = [treap_data[m] for m in metrics]

x = range(len(metrics))
width = 0.35

axes[0, 0].bar([i - width/2 for i in x], bst_times, width, label='BST', color='blue')
axes[0, 0].bar([i + width/2 for i in x], treap_times, width, label='Treap', color='red')
axes[0, 0].set_xlabel('Operation')
axes[0, 0].set_ylabel('Time (ms)')
axes[0, 0].set_title('Basic Operations Time')
axes[0, 0].set_xticks(x)
axes[0, 0].set_xticklabels(['Insert', 'Search', 'Delete'])
axes[0, 0].legend()
axes[0, 0].grid(True, axis='y')

# Add value labels on bars
for i, (bst_t, treap_t) in enumerate(zip(bst_times, treap_times)):
    axes[0, 0].text(i - width/2, bst_t, f'{bst_t:.1f}', ha='center', va='bottom', fontsize=8)
    axes[0, 0].text(i + width/2, treap_t, f'{treap_t:.1f}', ha='center', va='bottom', fontsize=8)

# Graph 2: getMostPopular & getMostRecent Comparison
metrics2 = ['getMostPopular (ms)', 'getMostRecent (ms)']
bst_times2 = [bst_data[m] for m in metrics2]
treap_times2 = [treap_data[m] for m in metrics2]

x2 = range(len(metrics2))
axes[0, 1].bar([i - width/2 for i in x2], bst_times2, width, label='BST', color='blue')
axes[0, 1].bar([i + width/2 for i in x2], treap_times2, width, label='Treap', color='red')
axes[0, 1].set_xlabel('Operation')
axes[0, 1].set_ylabel('Time (ms)')
axes[0, 1].set_title('Query Operations Time')
axes[0, 1].set_xticks(x2)
axes[0, 1].set_xticklabels(['getMostPopular', 'getMostRecent'])
axes[0, 1].legend()
axes[0, 1].grid(True, axis='y')

# Add value labels
for i, (bst_t, treap_t) in enumerate(zip(bst_times2, treap_times2)):
    axes[0, 1].text(i - width/2, bst_t, f'{bst_t:.2f}', ha='center', va='bottom', fontsize=8)
    axes[0, 1].text(i + width/2, treap_t, f'{treap_t:.2f}', ha='center', va='bottom', fontsize=8)

# Graph 3: Tree Height Comparison
heights = [bst_data['Tree Height'], treap_data['Tree Height']]
bars = axes[0, 2].bar(['BST', 'Treap'], heights, color=['blue', 'red'])
axes[0, 2].set_ylabel('Height')
axes[0, 2].set_title('Tree Height Comparison')
axes[0, 2].grid(True, axis='y')

for bar, height in zip(bars, heights):
    axes[0, 2].text(bar.get_x() + bar.get_width()/2., height,
                    f'{int(height):,}',
                    ha='center', va='bottom', fontweight='bold')

# Graph 4: Balance Factor Comparison
balance = [abs(bst_data['Balance Factor']), abs(treap_data['Balance Factor'])]
bars = axes[1, 0].bar(['BST', 'Treap'], balance, color=['blue', 'red'])
axes[1, 0].set_ylabel('|Balance Factor|')
axes[1, 0].set_title('Balance Factor (closer to 0 = better)')
axes[1, 0].grid(True, axis='y')

for bar, bf in zip(bars, balance):
    axes[1, 0].text(bar.get_x() + bar.get_width()/2., bf,
                    f'{int(bf):,}',
                    ha='center', va='bottom', fontweight='bold')

# Graph 5: getMostPopular Time (shows O(1) vs O(n))
popular_times = [bst_data['getMostPopular (ms)'], treap_data['getMostPopular (ms)']]
bars = axes[1, 1].bar(['BST', 'Treap'], popular_times, color=['blue', 'red'])
axes[1, 1].set_ylabel('Time (ms)')
axes[1, 1].set_title('getMostPopular()\nBST: O(n) vs Treap: O(1)')
axes[1, 1].grid(True, axis='y')

for bar, time in zip(bars, popular_times):
    axes[1, 1].text(bar.get_x() + bar.get_width()/2., time,
                    f'{time:.2f}',
                    ha='center', va='bottom', fontweight='bold')

# Graph 6: Summary Stats
axes[1, 2].axis('off')

# Calculate speedup ratios
insert_speedup = bst_data['Insert Time (ms)'] / treap_data['Insert Time (ms)'] if treap_data['Insert Time (ms)'] > 0 else float('inf')
search_speedup = bst_data['Search Time (ms)'] / treap_data['Search Time (ms)'] if treap_data['Search Time (ms)'] > 0 else float('inf')
height_ratio = bst_data['Tree Height'] / treap_data['Tree Height'] if treap_data['Tree Height'] > 0 else float('inf')

summary_text = f"""
SUMMARY STATISTICS
==================

Data Size: {int(bst_data['Data Size']):,} posts

BST:
  - Insert Time: {bst_data['Insert Time (ms)']:,.2f} ms
  - Search Time: {bst_data['Search Time (ms)']:,.2f} ms
  - Tree Height: {int(bst_data['Tree Height']):,}
  - Balance Factor: {int(bst_data['Balance Factor']):,}
  - getMostPopular: O(n)

Treap:
  - Insert Time: {treap_data['Insert Time (ms)']:,.2f} ms
  - Search Time: {treap_data['Search Time (ms)']:,.2f} ms  
  - Tree Height: {int(treap_data['Tree Height']):,}
  - Balance Factor: {int(treap_data['Balance Factor']):,}
  - Rotations: {int(treap_data['Rotations']):,}
  - getMostPopular: O(1)

PERFORMANCE GAINS:
  - Insert: Treap is {insert_speedup:.1f}x faster
  - Search: Treap is {search_speedup:.1f}x faster
  - Height: Treap is {height_ratio:.0f}x smaller

WINNER: Treap
"""
axes[1, 2].text(0.05, 0.5, summary_text, fontsize=9, fontfamily='monospace',
                verticalalignment='center', transform=axes[1, 2].transAxes,
                bbox=dict(boxstyle='round', facecolor='lightgray', alpha=0.3))

plt.tight_layout()
plt.savefig('reddit_performance_graphs_100k.png', dpi=150, bbox_inches='tight')
plt.show()

print("Graph saved as: reddit_performance_graphs_100k.png")
print(f"\nData Size: {int(bst_data['Data Size']):,} posts")
print(f"BST Height: {int(bst_data['Tree Height']):,}")
print(f"Treap Height: {int(treap_data['Tree Height']):,}")
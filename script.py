import os
import re

# Define the directory paths
dir_paths = ['C:\\Users\\Nikhilesh\\School\\College\\DSA\\leetcode', 'C:\\Users\\Nikhilesh\\School\\College\\DSA\\gfg']

# Create a set to store unique problem numbers and a dictionary to store problem counts per subfolder
unique_problems = set()
subfolder_counts = {}

# Use os.walk() to iterate over each file in the directories and their subdirectories
total_problems = 0
for dir_path in dir_paths:
    for root, dirs, files in os.walk(dir_path):
        for filename in files:
            # If we're in the 'leetcode' directory, extract the prefix number from the filename using regex
            if 'leetcode' in dir_path:
                problem_number = re.match(r'(\d+)', filename)
                if problem_number:
                    # Add the problem number to the set of unique problems
                    unique_problems.add(problem_number.group())
            total_problems += 1

            # Increment the count for the current subfolder
            subfolder = os.path.basename(root)
            if subfolder not in subfolder_counts:
                subfolder_counts[subfolder] = 0
            subfolder_counts[subfolder] += 1

# Open the README.md file and write the total problem count, unique problem count, and problem count for each subfolder
with open('README.md', 'w') as f:
    f.write('# Problem Solving Tracker\n\n')
    f.write(f'**Total Problems Solved:** {total_problems}\n\n')
    f.write(f'**Total Unique Problems Solved:** {len(unique_problems)}\n\n')
    f.write('## Problems Solved by Category\n\n')
    for subfolder, count in sorted(subfolder_counts.items(), key=lambda item: item[1], reverse=True):
        f.write(f'- **{subfolder.capitalize()}:** {count}\n')
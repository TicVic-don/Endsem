# read csv file vickey-credit_calculation.csv and calculate the credit score and cgpa of the students
import pandas as pd
import numpy as np

sum = 0
df = pd.read_csv('vickey_credit_calculation.csv')
for i in range(len(df)):
    sum+=df['c'][i]*df['g'][i]

print((sum - 16) / 116)
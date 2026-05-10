import numpy as np
import pandas as pd
from sklearn import linear_model
import seaborn as sea
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from scipy import stats

class voltage_filter:

	def __init__(self,df,X=None,target=None):
		self.X = X
		self.target = target
		self.df = df
		
		self.x_train = None
		self.x_test = None
		self.y_train = None
		self.y_test = None
	
	def data_preproc(self):
      
		#parameters definitions
		self.df_new = self.df.drop_duplicates()
		
		self.X = self.df_new[["Current (A)", "Power Usage (kW)", "Frequency (Hz)", "Fault Indicator"]]
		self.target = self.df_new["Voltage (V)"]
		
		#train && test samples
		#self.x_train,self.x_test,self.y_train,self.y_test = train_test_split(self.X,self.target, test_size = 0.32, random_state = 42);
        
		#temporal split
		train_sample = int(len(self.X) * (1 - 0.32))
		self.x_train = self.X[:train_sample]
		self.x_test = self.X[train_sample:]
		self.y_train = self.target[:train_sample]
		self.y_test = self.target[train_sample:]
        
	def preproces(self):
		#box-cox
		self.y_renow, self.lambda_data = stats.boxcox(self.y_train + 1e-10)
		#print(f'optimal lambda value: {lambda_data}')

		self.y_train_renow = stats.boxcox(self.y_train + 1e-10, lmbda = self.lambda_data)
		self.y_test_renow = stats.boxcox(self.y_test + 1e-10, lmbda = self.lambda_data)

		self.y_original = np.power((self.y_renow * self.lambda_data + 1), 1/self.lambda_data)

	def visualization(self):
		plt.subplot(1,2,1)
		plt.title("Box-Cox voltage data")
		sea.histplot(self.y_renow,kde='True')
		plt.xlabel('value')
		plt.ylabel('voltage_contage')
		
		plt.subplot(1,2,2)
		plt.title("Voltage data")
		sea.histplot(self.y_original,kde='True')
		plt.xlabel('value')
		plt.ylabel('voltage')
		plt.show()
		


df1 = pd.read_csv('dataset/smart_grid_dataset.csv')

v_f = voltage_filter(df1)
v_f.data_preproc()
v_f.preproces()
v_f.visualization()

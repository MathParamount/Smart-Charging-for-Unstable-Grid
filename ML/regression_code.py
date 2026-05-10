from data_box_cox_f import *

from sklearn.linear_model import LinearRegression

class regression:
	
	def linregresion(self,v_f):
		
		self.reg = LinearRegression().fit(v_f.X,v_f.target)
		
		self.train_score = self.reg.score(v_f.x_train,v_f.y_train)
		self.test_score = self.reg.score(v_f.x_test,v_f.y_test)
		
		#print(f"training R² score: {train_score}")
	   #print(f"test R² score: {test_score}")
		
		##gett coefficient
		self.coeffc = self.reg.coef_
		#print(f"coefficient: {coeffc}")
		
		##get intercept
		self.interc = self.reg.intercept_
		#print(f"intercept: {interc}")
		
		self.prediction = self.reg.predict(v_f.x_test)
		
		##shape verification
		#print(f"size of y_original: {v_f.y_original.shape}")
		#print(f"size of prediction: {self.prediction.shape}")
		
		self.y_original_new = v_f.y_original[:321]

		##Residuo
		self.resd = v_f.y_test - self.prediction
		
		#print(f"media residuo: {resd.mean():.4f}")
		
		#Saving data with class atributes
		self.x_train = v_f.x_train
		self.x_test = v_f.x_test
		self.y_train = v_f.y_train
		self.y_test = v_f.y_test

		#plot of residuo x prediction
		#plt.title("residuo x prediction")
		#plt.scatter(resd, self.prediction)
		#plt.axhline(y=0, color = 'r', linestyle = '--')
		#plt.show()

		return {
			'model': self.reg,
			'train_score': self.train_score,
			'test_score': self.test_score,
			#'coefficient': coeffc,
			#'intercept': interc,
			'predicition': self.prediction
		}

#instance of the pather class
df2 = pd.read_csv('dataset/smart_grid_dataset.csv')
v_f = voltage_filter(df2)
v_f.data_preproc()
v_f.preproces()

reg_f = regression()
reg_f.linregresion(v_f)

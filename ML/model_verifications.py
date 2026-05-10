from data_box_cox_f import *
from regression_code import *

#Global critical voltage (STM32 referc)
v_critico_low_adc = 0.83 * v_f.target
v_unstable_min_adc = 0.95 * v_f.target

v_critico_high_adc = 1.15 * v_f.target


class verification_model:
	def verf(self,reg_f):
		#Optimal lambda value(box-cox)
		print(f"optimal lambda value: {v_f.lambda_data}")

		#train and test score
		print(f"training R² score: {reg_f.train_score}")
		print(f"test R² score: {reg_f.test_score}")
		
		#shape verification
		print(f"x_train shape: {reg_f.x_train.shape}")
		print(f"x_test shape: {reg_f.x_test.shape}")
		print(f"y_train shape {reg_f.y_train.shape}")
		print(f"y_test shape {reg_f.y_test.shape}")

		print(f"size of prediction: {reg_f.prediction.shape}")
		
		#Model coefficient
		print(f"coefficient: {reg_f.coeffc}")
		print(f"intercept: {reg_f.interc}")
        
      #prediction plot
		plt.subplot(1,2,1)
		plt.title("Voltage prediction X original")
		plt.scatter(reg_f.y_original_new,reg_f.prediction,alpha = 0.3)
		
		plt.subplot(1,2,2)
		plt.title("Voltage prediction")
		plt.plot(reg_f.prediction)
		plt.show()
        
		#media residuo
		print(f"media residuo: {reg_f.resd.mean():.4f}")
		

		#plot of residuo x prediction
		plt.title("residue x prediction")
		sea.histplot(data = v_f.df_new, x= reg_f.resd)
		#plt.scatter(reg_f.resd, reg_f.prediction)
		#plt.axhline(y=0, color = 'r', linestyle = '--')
		plt.show()
		
		#plot prediction x time
		fig, (ax1,ax2) = plt.subplots(2,1,figsize = (10,8))      #SUbplot with 2 graphs
		
		step = 80;		#test step samples

		ax1.plot(v_f.df_new["Timestamp"][::step],reg_f.prediction[:13])	#plot definition
		ax1.set_title("Prediction x time")
		
		ax2.plot(v_f.df_new["Timestamp"][::step], v_f.target[:13])
		ax2.set_title("Voltage x time")
		plt.tight_layout()      #Spacement adjust
		plt.show()


		#model validation
		v_measured = reg_f.prediction - v_f.target[679:];

		#plot instability
		plt.title("prediction error over time")
		plt.suptitle("model validation", fontsize= 16)
		plt.plot(v_measured)
		plt.axhline(0, color='red', linestyle='--')     #Line zero erro
		plt.show()
		
		#overfitting test
		diff_modl = abs(reg_f.train_score - reg_f.test_score)
		print(f"difference of train and test: {diff_modl}")
		if (diff_modl > 0.1):
			print("Possible overfitting")
  

	def result(self,reg_f):
		#Verify if the prediction is bellow of any prediction values
		
		if (reg_f.prediction[:,None] < v_critico_low_adc.values).any():
			action = "shutdown"
			instability_level = 2
	    
		elif (reg_f.prediction[:,None] < v_unstable_min_adc.values).any():
			action = "reduce charge"
			instability_level = 1
	    
		elif (reg_f.prediction[:,None] > v_critico_high_adc.values).any():
			action = "emergency high voltage"
			instability_level = 2
	    
		else:
			action = "normal condition"
			instability_level = 0
	    
	    
		output_hardw = reg_f.prediction[0]
        
		print(f"\nvoltage prediction: {output_hardw}, condition: {action}, instability_level: {instability_level}")

		return output_hardw

df3 = pd.read_csv('dataset/smart_grid_dataset.csv')
v_f = voltage_filter(df3)
v_f.data_preproc()
v_f.preproces()

reg_f = regression()
reg_f.linregresion(v_f)		#train and salve score

verifc = verification_model()
verifc.verf(reg_f)
verifc.result(reg_f)

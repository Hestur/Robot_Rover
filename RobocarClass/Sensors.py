#Base class
class Standard_Sensor:
    def __init__ (self, Name, Sensor_Type):
        self.Name = Name
        self.sensor_type = Sensor_Type
    
    def getReading(self):
        print("Getting reading")
#SubClass of Standard_Sensor  
class Dust_Sensor(Standard_Sensor):
    def __init__(self, Name, Sensor_Type):
        super().__init__(Name, Sensor_Type)
        print("Dust is rdy")
#SubClass of Standard_Sensor            
class Gas_Detector(Standard_Sensor):
    def __init__(self, Name, Sensor_Type):
        super().__init__(Name, Sensor_Type)
        print("Gas is rdy")    
#Main for test           
def main():
    testsensor = Gas_Detector("gas_detc","Gas")
    print(testsensor.Name)
    testsensor.getReading() 
main()
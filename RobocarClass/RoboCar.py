#The RoboCar Class definitions
from User_Interface import Terminal_Interface
import Sensors
#from Mission_Handler import Mission_Handler
from enum import Enum

class States(Enum):
  IDLE            = 0
  HANDLE_MISSION  = 1
  HANDLE_SENSORS  = 2
  HANDLE_ROVER    = 3
  VISUALIZE_DATA  = 4
  
class RoboCar:
  def __init__(self, Name, IF_Type):
    self.__Name = Name
    self.__IF_Type = IF_Type
    self.__State = States.IDLE

    # User Interface Object is created and RoboCar object reference is passed down
    
    self.MyFace = Terminal_Interface(self)
 

    # Mission Handler Object is created 
    # self.MyMission = Mission_Handler()
    
    # Add more attributes here...

    #Start the Main RoboCar Loop
    self.Main_Loop()

  def Idle(self):
    print('idle')
    

  def HandleMissions(self):
    print('handle mission')
    

  def HandleSensors(self):
    print('handle sensors')
    

  def HandleRover(self):
    print('handle rover')
  
  def VisualizeData(self):
    print('visualize data')

  def Get_Interface_Type(self):
    return self.__IF_Type

  def Set_Name(self, Name):
    self.__Name = Name

  def Get_Name(self):
    return self.__Name

  def Set_State(self, State):
    self.__State = State

  def Get_State(self):
    return self.__State

  def Main_Loop(self):

    quit = False
        
    actions = {States.IDLE:           self.Idle,
               States.HANDLE_MISSION: self.HandleMissions,
               States.HANDLE_SENSORS: self.HandleSensors,
               States.HANDLE_ROVER:   self.HandleRover,
               States.VISUALIZE_DATA: self.VisualizeData}

    while not quit:
      key = self.MyFace.Read_Key()
      if key == 'q':
        quit = True
  
      if key == '1':
        self.Set_State(States.HANDLE_MISSION)
      elif key == '2':
        self.Set_State(States.HANDLE_SENSORS)
      elif key == '3':
        self.Set_State(States.HANDLE_ROVER)
      elif key == '4':
        self.Set_State(States.VISUALIZE_DATA)

      #else:
       # print('else')

      action = actions.get(self.__State)
      action()

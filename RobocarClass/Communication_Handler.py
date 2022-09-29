import paho.mqtt.client as mqtt

client = mqtt.Client()
client.connect()# here we insert the IP/address we want to subscribe, 1883, 60
client.subscribe()#here we insert the specific topic

class Communication_handler:
    def init(self):

    def set_data(self, set_data):
        self.set_data=set_data

    def get_data(self,to_retrieve):
        self.to_retrieve=to_retrieve
        return to_retrieve

    def send_data(self): # here we get data from Mission handler and publish it
        client.publish()#format=subscriber,message,qos=0, retain=False
    def retrieve_data(self, result):# here we get data from broker
        self.__result=result

#run=True

#while run:
#    client.loop()
PHONE = 192.168.1.200

all:
	pebble build
	pebble install --phone $(PHONE) &

logs:
	pebble logs --phone $(PHONE)


debug:	
 



PHONE = 172.31.50.248

all:
	pebble build
	pebble install --phone $(PHONE) &

logs:
	pebble logs --phone $(PHONE)


debug:	
 



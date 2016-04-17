PHONE = 172.31.51.193

all:
	pebble build
	pebble install --phone $(PHONE) &

logs:
	pebble logs --phone $(PHONE)


debug:	
 



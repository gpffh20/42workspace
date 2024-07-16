all : up

up :
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

down :
	@rm -rf ~/Desktop/inception
	@docker-compose -f ./srcs/docker-compose.yml down

stop :
	@docker-compose -f ./srcs/docker-compose.yml stop

start :
	@docker-compose -f ./srcs/docker-compose.yml start

prune:
	@docker system prune

status :
	@docker ps

.PHONY: all up down stop start status prune
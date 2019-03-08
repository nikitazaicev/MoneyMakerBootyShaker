set search_path = EXPO;

DROP TABLE expo.timestats CASCADE;

CREATE TABLE expo.timestats (
Id varchar(100) NOT NULL,
Score int,
Tiden timestamp NOT NULL,
PRIMARY KEY (Id, Tiden),
FOREIGN KEY (Id) REFERENCES expo.Stand(Id)
);

INSERT INTO expo.stand (Id,Score) VALUES 
	('1',5);

INSERT INTO expo.timestats (Id,Score,Tiden) VALUES 
	('1','0',now())
	

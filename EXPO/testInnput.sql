set search_path = EXPO;

DROP TABLE expo.timestats CASCADE;
DROP TABLE expo.stand CASCADE;

CREATE TABLE expo.stand (
Id varchar(100) NOT NULL, 
Score int,
antStemmer int,
PRIMARY KEY (Id)
);

CREATE TABLE expo.timestats (
stand_id varchar(100) NOT NULL,
Score int,
Tiden timestamp NOT NULL,
PRIMARY KEY (stand_id, Tiden),
FOREIGN KEY (stand_id) REFERENCES expo.Stand(Id)
);

INSERT INTO expo.stand (Id,Score,antStemmer) VALUES 
	('1',0,0),
	('2',0,0),
	('3',0,0);
	

INSERT INTO expo.timestats (stand_id,Score,Tiden) VALUES 
	('1','0',now()),
	('2','0',now()),
	('3','0',now())
-- project3 procedure

delimiter //

DROP PROCEDURE IF EXISTS login//
CREATE PROCEDURE login(IN username VARCHAR(20), IN userpassword VARCHAR(10))
BEGIN
	IF EXISTS (SELECT * FROM student WHERE username = Name AND userpassword = password) 
    THEN
        SELECT * FROM student WHERE username = Name AND userpassword = password;
	END IF;
END//

DROP PROCEDURE IF EXISTS list_current_courses//
CREATE PROCEDURE list_current_courses(IN id INT(11))
BEGIN
	IF MONTH(CURDATE()) >= 9 ||  MONTH(CURDATE()) <= 2
    THEN
		SET @Q = 'Q1';
	ELSE
		SET @Q = 'Q2';
	END IF;
    IF MONTH(CURDATE()) <= 2
    THEN
		SET @Y = YEAR(CURDATE()) - 1;
	ELSE
		SET @Y = YEAR(CURDATE());
	END IF;
	SELECT * 
    FROM transcript NATURAL JOIN unitofstudy
    WHERE studid = id AND year = @Y AND semester = @Q;
END//

delimiter ;

-- login procedure
delimiter //
DROP PROCEDURE IF EXISTS login//
CREATE PROCEDURE login(IN username VARCHAR(20), IN userpassword VARCHAR(10), OUT flag BOOLEAN)
BEGIN
	IF EXISTS (SELECT * FROM student WHERE username = Name AND userpassword = password) 
    THEN
		SET flag = TRUE;
	ELSE 
		SET flag = FALSE;
	END IF;
END//

delimiter ;

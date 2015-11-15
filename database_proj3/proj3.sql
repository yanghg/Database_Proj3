-- login procedure
delimiter //
DROP PROCEDURE IF EXISTS login//
CREATE PROCEDURE login(IN username VARCHAR(20), IN userpassword VARCHAR(10))
BEGIN
	IF EXISTS (SELECT * FROM student WHERE username = Name AND userpassword = password) 
    THEN
        SELECT * FROM student WHERE username = Name AND userpassword = password;
	END IF;
END//

delimiter ;
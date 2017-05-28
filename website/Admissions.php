<!DOCTYPE html>
<html lang="en">
<head>
	<title> Rambhakta Memorial School </title>
	<meta charset="utf-8" />
	<link rel="stylesheet"  href="style.css" type="text/css"/> 
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>	
	<body>

		<div id="container">
		<div id="header">
		<img src="RMS_log.jpg" height="180" width= "100%" alt="RMs_Logo" align="center">
		</div>
		<hr>
		
			<div id="navigation">
				<table id="tablestyle" width="100%" height="20px">
				<tr>
					<td><a href="index.php"><h3>Home </h3></a></td>
					<td><a href="Admissions.php"><h3>Admissions</h3></a></td> 
					<td><a href="teachers.php"><h3>Teachers</h3></a></td>
					<td><h3><a href="token_records.php">Token Records</a></h3></td>
					<td><h3><a href="about_us.php">About US</a></h3></td>
					<td><h3><a href="contact.php">Contact</a></h3></td>
				</tr>
				</table>
			</div>
		<hr>
		<table>
			<tr>
				
				<td width="150">
					<div class="left_bar">
						<a href="login.php">Log in</a><br>
						<a href="login_teachers.php">As teacher</a><br>
						<?php	
						
						for($i=0;$i<=16;$i++)
						{
							echo ".<br>";
						}
						?>
					</div>
				</td>
				
				<td width="700">
					<div class="mid">
					<h1>Admissions</h1>
						<p>
							RMS takes annual entrance exam for the new students at the month of CHAITRA every year. The selected candidates after<br>
							entrance test can do their admissions to join RMS. <br>
							This year the the date for form distribution  starts from 25 of CHAITRA. The final date to collect the form for entrance <br>
							examination is 28th CHAITRA.<br>
							<br> There isn't yearly admission system in RMS. A student should do their admission only three times in his time in RMS.<br>
							The students have to do their admission for KINDERGARTEN, CLASS ONE and CLASS SIX. In the name of yearly admission the <br>
							students fee for the month of BAISHAK should should be paid. After the payment of the fee for BAISHAK the students can get<br>
							their roll number. 
							<br><br>
							Detail information on the admission process and fee stucture is gien bellow.<br>
						</p>
					</div>
				</td>
				
				<td width="150">
					<div class="right_bar">
						Right bar
						<?php	
						
						for($i=0;$i<=17;$i++)
						{
							echo ".<br>";
						}
						?>
					</div>
				</td>
			</tr>
		</table>
	<div id="main-footer">
		<p><marquee>Copyright &copy 2014. Powered by: Power Ranger SPD, Red:Sujal Kokh Shrestha, Blue: Sajan Pasachhe, Green: Bibek Duwal, Yellow: Diva Nepal, Pink: Hazel Thapa</marquee></p>
	</div>
	</body>
	
	
		
	</head>
</html>

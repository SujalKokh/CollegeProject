<!DOCTYPE html>
<html lang="en">
<head>
	<title> Rambhakta Memorial School </title>
	<meta charset="utf-8" />
	<link rel="stylesheet"  href="style.css" type="text/css"/> 
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>	
	<body background="backgroung.jpg">
	
		<div id="container">
		<div id="header">
		<img src="logoe.jpg" height="75" width="100%" alt="RMS_logo" align="center">
		</div> 
	
				<div id="navigation">
				
			<div id='cssmenu'>
<ul>
	<li><a href="index.php"><span>Home</span></a></li>
	<li><a href="Admission.php"><span>Admission</span></a>
   <li><a href="teacher.php"><span>Teachers</span></a></li>
   
   <li class='last'><a href="Token.php"><span>Tokens</span></a></li>
   <li class='last'><a href="about_us.php"><span>About Us</span></a></li>
   <li class='active has-sub'><a href="login.php"><span>LOG IN</span></a>
      <ul>
         <li class='has-sub'><a href="login_teacher.php"><span>teacher</span></a>
        
         </li>
         <li class='has-sub'><a href="form2.php"><span>Students</span></a>
      
         </li>
      </ul>
   </li>
</ul>
			</div>
		<table>
			<td width="150">
					<div class="left_bar">
						<a href="login.php">Log in</a><br>
						<a href="login_teachers.php">As teacher</a><br>
						<?php	
						
						for($i=0;$i<=17;$i++)
						{
							echo "&nbsp<br>"; 
						}
						?>
					</div>
				</td>
				
				<td width="900">
					<div class="mid">
					<h1>Admissions</h1>
						<p>
							RMS takes annual entrance exam for the new students at the month of CHAITRA every year. The selected candidates after<br>
							entrance test can do their admissions to join RMS. <br>
							This year the the date for form distribution  starts from 25 of CHAITRA. The final date to collect the form for entrance <br>
							examination is 28th CHAITRA.<br>
							<br> There isn't yearly admission system in RMS. A student should do their admission only three times in his time in RMS.<br>
							The students have to <br>
							do their admission for KINDERGARTEN,<br> CLASS ONE and CLASS SIX. In the name of yearly admission the <br>
							students fee for the month of BAISHAK should should be paid. After the payment of the fee for BAISHAK the students can get<br>
							their roll number. 
							<br><br>
							Detail information on the admission process and fee stucture is gien bellow.<br>
						</p>
					</div>
				</td>
		
				
			</tr>
		</table>
	
		</table>
	<div id="main-footer">
		<p>Copyright &copy 2014. Powered by:Mythcrews Studio Pvt. Ltd </p>
	</div>
	</body>
	
	
		
	</head>
</html>

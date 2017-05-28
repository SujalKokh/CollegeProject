<html>
<head>
<title>calendar</title>
</head>
<body>
<?php
	$now = getdate(time());
	$time = mktime(0,0,0, $now['mon'], 1, $now['year']);
	$date = getdate($time);
	$dayTotal = cal_days_in_month(0, $date['mon'], $date['year']);
	//Print the calendar header with the month name.
	print '<table width="98%" ><tr><td colspan="7"><strong>' . $date['month'] . '</strong></td></tr>';
	for ($i = 0; $i < 6; $i++) {
		print '<tr bgcolor="skyblue">';
		for ($j = 1; $j <= 7; $j++) {
			$dayNum = $j + $i*7 - $date['wday'];
			//Print a cell with the day number in it.  If it is today, highlight it.
			print '<td';
			if ($dayNum > 0 && $dayNum <= $dayTotal) {
				print ($dayNum == $now['mday']) ? ' style="background: white;">' : '>';
				print $dayNum;
			}
			else {
				//Print a blank cell if no date falls on that day, but the row is unfinished.
				print '>';
			}
			print '</td>';
		}
		print '</tr>';
		if ($dayNum >= $dayTotal && $i != 6)
			break;
	}
	print '</table>';
?>
</body>
</html>
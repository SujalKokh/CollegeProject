<html>
<head>
</head>
<body>
<?php
$con = mysql_connect("localhost","root","");
if(!$con){
die("Can not connect:" . mysql_error());
}

mysql_select_db("pasachhe",$con);

// for add update and delete queries

if(isset($_POST['update'])){
$UpdateQuery ="UPDATE lectures Set Topic='$_POST[topic]', Name='$_POST[name]',Token='$_POST[token]' WHERE Topic='$_POST[hidden]'";
mysql_query($UpdateQuery,$con);
};

if(isset($_POST['delete'])){
$DeleteQuery="DELETE FROM lectures WHERE Topic='$_POST[hidden]'";
mysql_query($DeleteQuery,$con);
};

if(isset($_POST['add'])){
$AddQuery="INSERT INTO lectures (Topic, Name, Token) VALUES ('$_POST[utopic]','$_POST[uname]','$_POST[utoken]')";
mysql_query($AddQuery,$con);
};

//end query connection



$sql ="SELECT * FROM lectures";
$myData = mysql_query($sql,$con);
echo"<table border=1>
<tr>
<th>Topic</th>
<th>Name</th>
<th>Token</th>
</tr>";
while($record = mysql_fetch_array($myData)){
echo "<form action=datas.php method=post>";
echo"<tr>";
echo"<td>" . "<input type = text name=topic value=" . $record['Topic'] . " </td>";
echo"<td>" . "<input type = text name=name value=" . $record['Name'] . " </td>";
echo"<td>" . "<input type = text name=token value=" . $record['Token'] . " </td>";
echo"<td>" . "<input type = hidden name=hidden value=" . $record['Topic'] . " </td>";
echo"<td>" . "<input type = submit name=update value=update" . " </td>";
echo"<td>" . "<input type = submit name=delete value=delete" . " </td>";
echo"</tr>";
echo"</form>";
}
echo "<form action=datas.php method=post>";
echo "<tr>";
echo "<td><input type=text name=utopic></td>";
echo "<td><input type=text name=uname></td>";
echo "<td><input type=text name=utoken></td>";
echo "<td>" . "<input type = submit name=add value=add " . "</td>";
echo"</tr>";
echo "</form>";
echo "</table>";
mysql_close($con);

?>
</body>
</html>


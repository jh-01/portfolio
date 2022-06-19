<?php
$conn = mysqli_connect(
    "127.0.0.1",
    "root",
    "496500",
    "test"
);

$sql = "SELECT * FROM members";
$res = mysqli_query($conn, $sql);
$flag = false;
$id = '';

if($res === false){
    echo "문제 발생";
    error_log(mysqli_error($conn));
} else {
    while($row = mysqli_fetch_array($res)){
        $escaped_id = htmlspecialchars($row['userid']);
        $escaped_pass = htmlspecialchars($row['pass']);
        if($escaped_id == $_POST['userid']){
            if($escaped_pass == $_POST['pass']){
                $flag = true;
                $id = $row['id'];
            }
        }
    };
    if($flag == true){
        echo "<script>location.href='lib/login.php?id={$id}'</script>";

    } else {
        echo "해당 유저 없음";
    }
}
?>

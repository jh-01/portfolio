<?php
$conn = mysqli_connect(
    "127.0.0.1",
    "root",
    "496500",
    "test"
);

if($_POST['name'] === '/x'){
  echo "<script>location.href='../index.html'</script>";
}

$filtered = array(
    'name'=>mysqli_real_escape_string($conn, $_POST['name']),
    'userid'=>mysqli_real_escape_string($conn, $_POST['userid']),
    'pass'=>mysqli_real_escape_string($conn, $_POST['pass'])
  );
  
$sql = "
    INSERT INTO members
      (name, userid, pass)
      VALUES(
          '{$filtered['name']}',
          '{$filtered['userid']}',
          '{$filtered['pass']}'
      )
";

$res = mysqli_query($conn, $sql);

if($res === false){
    echo '저장하는 과정에서 문제가 생겼습니다. 관리자에게 문의해주세요.';
    error_log(mysqli_error($conn));
} else {
    echo '성공했습니다. <a href="../index.html">돌아가기</a>';
}

?>

<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Signup Page</title>
    <link rel="stylesheet" type="text/css" href="style.css?v1">
  </head>
  <body>
    <div class="intro4">
    </div>
  </body>
</html>

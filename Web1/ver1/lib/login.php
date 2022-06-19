<?php
$conn = mysqli_connect(
  "127.0.0.1",
  "root",
  "496500",
  "test");

$filtered = array(
  'name'=>mysqli_real_escape_string($conn, $_POST['name']),
  'userid'=>mysqli_real_escape_string($conn, $_POST['userid']),
);

$sql = "
  INSERT INTO author
    (name, profile)
    VALUES(
        '{$filtered['name']}',
        '{$filtered['profile']}'
    )
  ";

$res = mysqli_query($conn, $sql);
if($res === false){
  echo '저장하는 과정에서 문제가 생겼습니다. 관리자에게 문의해주세요.';
  error_log(mysqli_error($conn));
} else {
  //세션 시작
  session_start();

  //세션 변수 등록
  $_SESSION['userid'] = $filtered['name'];

  header('Location: author.php');
}
echo $sql;
 ?>

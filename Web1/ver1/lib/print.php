<?php
$conn = mysqli_connect(
    "127.0.0.1",
    "root",
    "496500",
    "test");

$sql = "SELECT * FROM members";
$res = mysqli_query($conn, $sql);
$list = '';
while($row = mysqli_fetch_array($res)){
    $escaped_title = htmlspecialchars($row['title']);
    $list = $list."<li><a href=\"index.php?id={$row['id']}\">{$escaped_title}</a></li>";
};

function print_title(){
  if(isset($_GET['id'])){
    echo htmlspecialchars($_GET['id']);
  } else{
    echo "welcome";
  }
}

function print_description(){
  if(isset($_GET['id'])){
    $basename = basename($_GET['id']);
    echo htmlspecialchars(file_get_contents('./data/'.$basename));
  }
  else {
    echo "Hello, PHP";
  }
}

function print_list(){
  $list = scandir('./data');
  $i = 0;
  while($i < count($list)){
    $title = htmlspecialchars($list[$i]);
    if($list[$i] != '.'){
      if($list[$i] != '..'){
        echo "<li>
        <a href=\"index.php?id=$title\">$title</a></li>\n";
      }
    }
    $i += 1;
  }
}
 ?>

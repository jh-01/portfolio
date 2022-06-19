<?php
    session_start();
    if(isset($_SESSION['unique_id'])){
        include_once "config.php";
        $logout_id = mysqli_real_escape_string($conn, $_GET['logout_id']);
        if(isset($logout_id)){
            $status = "Offline now";
            $sql = mysqli_query($conn, "UPDATE members SET status = '{$status}' WHERE unique_id={$_GET['logout_id']}");
            if($sql){
               $sql2 = mysqli_query($conn, "INSERT INTO messages (outgoing_msg_id, msg, notice)
                                              VALUES ({$_GET['logout_id']}, '..', 3)") or die();
                session_unset();
                session_destroy();
                header("location: http://prjshangrila38.dothome.co.kr/");
            }
        }else{
            // header("location: ../../index.html");
        }
    }else{
        header("location: http://prjshangrila38.dothome.co.kr/");
    }
?>

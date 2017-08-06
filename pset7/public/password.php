<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("password_form.php", ["title" => "Change Password"]);
    }
else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["new"]))
        {
            apologize("Please enter new passwords.");
        }
        else if (empty($_POST["confirm"]))
        {
            apologize("Please confirm your password.");
        }
        else if ($_POST["new"]!=$_POST["confirm"])
        {
            apologize("Passwords do not match.");
        }
        else
        {
            CS50::query("UPDATE users SET hash=?  WHERE id=?", password_hash($_POST["new"],PASSWORD_DEFAULT), $_SESSION["id"]);
            render("success.php");
        }
    }
    
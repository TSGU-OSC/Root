package my.code;

import java.sql.*;
import java.util.Scanner;

public class mysql {
    public static void main(String[] args) throws Exception{
        String url = "jdbc:mysql://127.0.0.1:3306";
        String username = "root";
        String password = "123456789";
        Connection connection = DriverManager.getConnection(url,username,password);
        Statement statement = connection.createStatement();

        //String sql="show databases";
        //ResultSet resultSet=statement.executeQuery(sql);
        //while(resultSet.next()){
        //    System.out.println(resultSet.getString(1));
        //}

        Scanner scanner = new Scanner(System.in);
        System.out.println("plz enter number: ");
        String number = scanner.nextLine();
        System.out.println("plz enter name: ");
        String name = scanner.nextLine();

        String use="use hello";
        String sql = """
                CREATE TABLE IF NOT EXISTS studentManager( 
                                number varchar(20),
                                name varchar(20) 
                                )charset=utf8
                """;
        String insert = "insert into studentManager(number,name) values"+"('"+number+"','"+name+"')";
        statement.executeUpdate(use);
        statement.executeUpdate(sql);
        int i=statement.executeUpdate(insert);
        if(i>0){
            System.out.println("register complete!");
        }else{
            System.out.println("register fail plz check your input!");
        }
        statement.close();
        connection.close();
    }
}

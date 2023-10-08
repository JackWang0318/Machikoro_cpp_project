# CPP Project 2022 Fall Semester

## Intro

Machikoro is a simple yet fun management board game for 2-4 players that uses dice and currency to build buildings with various functions. The first player to complete the four landmark buildings wins the game, and a single game lasts 20-30 minutes. 

![image](https://github.com/JackWang0318/Machikoro_cpp_project/assets/99715727/c16dbd06-e796-4f9a-a574-2fcb20207f2f)

  Our group used distributed cooperation to complete the implementation of the online application of "Machikoro" in the Clion compiler, including the selection of the game version, the functions and attributes of various ordinary buildings and landmarks, the attributes of the buildings and currencies owned by the players, the generation and setup of the computer players, the human-computer interaction page, and other basic functions. 
  On the basis of the above modules, the normal operation of Machikoro is initially realized. Players can operate the game on the desktop Desk of the program, and the player who meets the conditions will be automatically judged by the system to win. In addition, we designed to expand the card packs and gameplay of the port version, so that players can freely choose the gameplay and use different functional card packs. 


We used gitee to help us build our project, since the gitee repo is private, I moved it to this github repo for others to view.

### [Project Overview](https://github.com/JackWang0318/Machikoro_cpp_project/Machikoro_Project_Overview.pdf)

### [Video Demo Link](https://www.bilibili.com/video/BV1y24y1C7LG/?spm_id_from=333.999.0.0&vd_source=3cf6a25e20fce619b2d35930f06672e8)

### UML graph
![image](https://github.com/JackWang0318/Machikoro_cpp_project/assets/99715727/6f5360aa-8dfd-4437-b7a3-a90005aa1757)


#### gitee使用教程

0.  经过伦德clion的视频应该已经安装了git
1.  gitee基本设置：账号，密码，邮箱（重要）
2.  寻找自己的ssh公钥以及全局设置，方法见CSDN：
https://blog.csdn.net/maxle/article/details/124867297?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166486090216782248595046%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166486090216782248595046&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-124867297-null-null.142^v51^pc_rank_34_queryrelevant25,201^v3^control_1&utm_term=gitee&spm=1018.2226.3001.4187
3.  现在已经可以开始使用gitee了，相关命令代码教程见廖雪峰网站：
https://www.liaoxuefeng.com/wiki/896043488029600
教程虽然用的是github作为讲解，但是指令完全一致。

#### github使用教程
如何寻找ssh公钥？https://www.jb51.net/article/241929.htm
如果遇到Key is invalid.问题，我们应该注意自己选择的公钥是否正确，进入创建时自动产生的路径
在该文件夹内进入gitbash，并使用命令cat id_rsa.pub，查看ssh（格式为ssh-a开头）

#### 使用说明

1.  project的pdf见：https://gitee.com/lundechen/cpp/raw/master/project/POO_Projet_LO02_A22_v1.pdf
2.  项目代码在master分支untitle文件夹中
3.  使用git add，git commit或者clion右上角的commit按钮保存更改，使用git push把更改推送到远程库



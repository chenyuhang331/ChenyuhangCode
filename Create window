#include<glad/glad.h>
#include<GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//帧缓冲 大小 回调函数，  参数为函数指针 window, 渲染的视口的宽高
void processInput(GLFWwindow *window);
int main()
{
    glfwInit();
    glfWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3); //指定我们所要用到的opengl 版本 是3.3 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE); //使用opengl 的核心配置
    GLFWwindow* window=glfwCreateWindow(800,600,"LearnOpenGL",NULL,NULL); //初始化一个函数指针 window,并创建一个窗口 
    if(window==NULL)  //如果窗口创建失败
    {
        std::cout<<"Failed to create GLFW window"<<std::endl;
        glfwTerminate(); //释放
        return -1;
    }
    glfwMakeContextCurrent(window); //如果窗口创建成功 把窗口添加到 主线程的上下文里面。
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback); //当我们手动的改变窗口的大小时候调用

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))  //GLAD 函数指针的库的初始化
    {
        std::cout<<"Failed to initialize GLAD"<<std::endl;
        return -1;
    }
    while(!glfwWindowShouldClose(window)) //当窗口还没关呢
    {
        processInput(window); //获取键盘的输入事件
        glClearColor(0.2f,0.2f,0.2f,0.2f); 
        glClear(GL_CLOLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();  // 检查是否有事件的
        
    }
    glfwTerminate();
    return 0;





    return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0,800,600);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window,GLFW_KEY_ESCAPSE)==GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window,true);
    }    
}

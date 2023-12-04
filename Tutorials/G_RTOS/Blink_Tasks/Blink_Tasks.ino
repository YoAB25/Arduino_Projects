#include <Arduino_FreeRTOS.h>

#define PIN_RED 5 
#define PIN_GREEN 7

// Initialize functions parameters
void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);
void TaskPrint(void *pvParameters);

void setup() {
  // Start Serial communication
  Serial.begin(9600);
  
  // Task Creating : 
  // xTaskCreate( TaskFunction_t pvTaskCode, const char * const pcName, uint16_t usStackDepth, void *pvParameters, UBaseType_t uxPriority, TaskHandle_t *pxCreatedTask );
  xTaskCreate(TaskBlink1,"task1",128,NULL,1,NULL);
  xTaskCreate(TaskBlink2,"task2",128,NULL,0,NULL);
  xTaskCreate(Taskprint,"taskPrint",128,NULL,5,NULL);

  // Start the scheduler
  vTaskStartScheduler();
}

void TaskBlink1(void *pvParameters){
  pinMode(PIN_GREEN, OUTPUT);
  while(1){
    Serial.println("Task 2 is running");
    digitalWrite(PIN_GREEN, HIGH);
    // Delay function (safe version to prevent cpu from stopping and then freeRTOS)
    // portTICK_PERIOD_MS ! 
    vTaskDelay(200/portTICK_PERIOD_MS);
    // ...
    digitalWrite(PIN_GREEN, LOW);
    vTaskDelay(200/portTICK_PERIOD_MS);

  }
}

void TaskBlink2(void *pvParameters){
  pinMode(PIN_RED, OUTPUT);
  while(1){
    Serial.println("Task 1 is running");
    digitalWrite(PIN_RED, HIGH);
    // Delay function (safe version to prevent cpu from stopping and then freeRTOS)
    // portTICK_PERIOD_MS ! 
    vTaskDelay(200/portTICK_PERIOD_MS);
    // ...
    digitalWrite(PIN_RED, LOW);
    vTaskDelay(200/portTICK_PERIOD_MS);

  }
}

void Taskprint(void *pvParameters){
  int counter{};
  while(1){
    counter++;
    Serial.println(counter);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}


void loop() {
  // put your main code here, to run repeatedly:

}

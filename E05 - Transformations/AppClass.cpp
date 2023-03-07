#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Thomas Roman - tfr8811@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);

	//Allocate the memory for the Meshes
	
	m_uMeshCount = 48;
	for (int i = 0; i < m_uMeshCount; i++){
		m_pMeshList.push_back(new MyMesh());
		m_pMeshList[i]->GenerateCube(1.0f, C_BLACK);
	}
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();

	//make the invader
	int i = 0;
	float speed = 0.0f;
	speed += 0.1f;

	// row 1
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-3.0f+speed, 4.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(3.0f + speed, 4.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;

	// row 2
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-2.0f + speed, 3.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(2.0f + speed, 3.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;

	// row 3
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-3.0f + speed, 2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-2.0f + speed, 2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-3.0f + speed, 2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-2.0f + speed, 2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-1.0f + speed, 2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(0.0f + speed, 2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(1.0f + speed, 2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(2.0f + speed, 2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(3.0f + speed, 2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;

	// row 4
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-4.0f + speed, 1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-3.0f + speed, 1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-1.0f + speed, 1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(0.0f + speed, 1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(1.0f + speed, 1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(3.0f + speed, 1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(4.0f + speed, 1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;

	// row 5
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-5.0f + speed, 0.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-4.0f + speed, 0.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-3.0f + speed, 0.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-2.0f + speed, 0.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-1.0f + speed, 0.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(0.0f + speed, 0.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(1.0f + speed, 0.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(2.0f + speed, 0.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(3.0f + speed, 0.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(4.0f + speed, 0.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(5.0f + speed, 0.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;

	// row 6
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-5.0f + speed, -1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-3.0f + speed, -1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-2.0f + speed, -1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-1.0f + speed, -1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(0.0f + speed, -1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(1.0f + speed, -1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(2.0f + speed, -1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(3.0f + speed, -1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(5.0f + speed, -1.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;

	// row 7
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-5.0f + speed, -2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-3.0f + speed, -2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(3.0f + speed, -2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(5.0f + speed, -2.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;

	// row 8
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-2.0f + speed, -3.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(-1.0f + speed, -3.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(1.0f + speed, -3.0f, 0.0f))), ToMatrix4(m_qArcBall);
	i++;
	m_pMeshList[i]->Render(m4Projection, m4View, glm::translate(vector3(2.0f + speed, -3.0f, 0.0f))), ToMatrix4(m_qArcBall);



	// draw a skybox
	m_pModelMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pModelMngr->Render();

	//clear the render list
	m_pModelMngr->ClearRenderList();

	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//Release meshes
	for (int i = 0; i < m_uMeshCount; i++) {
		SafeDelete(m_pMeshList[i]);
	}

	//release GUI
	ShutdownGUI();
}
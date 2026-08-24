#pragma once

class CEngine
	: public CSingleton<CEngine>
{
private:
	HWND	m_hWnd;

	// 윈도우 해상도
	Vec2	m_vResolution;
	

public:
	Vec2 GetWindowResolution() const { return m_vResolution; }
	HWND GetMainWnd() const { return m_hWnd ; }

public:
	int init(HWND _hWnd, UINT _iWidth, UINT _iHeight);
	void progress() const;

private:
	void tick() const;
	void render() const;


public:
	CEngine();
    virtual ~CEngine() override;
};

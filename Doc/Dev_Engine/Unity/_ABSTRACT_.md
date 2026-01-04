# \_ABSTRACT\_：개요

## 목차

-   [\_ABSTRACT\_：개요](#_abstract_개요)
    -   [목차](#목차)
    -   [설치와 vscode 환경설정](#설치와-vscode-환경설정)
        -   [vscode 와 싱크 문제 해결](#vscode-와-싱크-문제-해결)
    -   [기본 조작](#기본-조작)
    -   [팁](#팁)
        -   [네이밍 컨벤션](#네이밍-컨벤션)
        -   [Shortcut 오브젝트](#shortcut-오브젝트)
        -   [2D 스프라이트 이미지 적용이 안될 경우](#2d-스프라이트-이미지-적용이-안될-경우)
        -   [Unity Remote 5](#unity-remote-5)
    -   [양식](#양식)
        -   [양식/터치 시스템](#양식터치-시스템)
        -   [양식/비주얼 노벨：Form/Visual Novel Genre](#양식비주얼-노벨formvisual-novel-genre)

## 설치와 vscode 환경설정

-   [Unity 공식 홈페이지](https://unity.com/kr/download/confirmation)에서 유니티 허브를 설치해주세요.

-   [MS 공식 홈페이지](https://dotnet.microsoft.com/ko-kr/download)에서 .NET SDK 를 설치해주세요. Visual Studio 설치는 필수가 아니나 Unity에서 C# 스크립트를 컴파일하고 실행하기 위한 .NET SDK는 별도로 설치되어 있어야 합니다.

    다음의 명령어로 .NET SDK 설치 여부를 확인할 수 있습니다.

    ```ps
    dotnet --list-sdks
    ```

-   vscode 에서 다음의 두 가지 확장이 필요합니다.

    -   C# Dev Kit (Microsoft 제공)
    -   Unity (Microsoft 제공, 기존 Unity Debugger 등을 대체하는 공식 확장팩입니다.)

-   Unity 에디터 설정을 vscode 로 변경하면 됩니다.

    -   Unity 에디터 상단 메뉴: Edit > Preferences (macOS는 Unity > Settings)
    -   External Tools 탭 클릭
    -   External Script Editor 항목에서 Visual Studio Code를 선택
    -   아래의 Regenerate project files 버튼을 눌러 프로젝트 파일을 갱신합니다.

### vscode 와 싱크 문제 해결

&nbsp; vscode 에디터에서 스크립트 변화가 있었으나 Unity 에디터 환경이 인식하지 못하는 경우가 있습니다. 이 경우 다음의 작업을 통해 refresh 작업을 진행해야 합니다.

-   Auto Refresh 설정 확인

    -   유니티가 외부 파일의 변경 사항을 자동으로 감지하는 기능이 꺼져 있을 수 있습니다.
    -   `Edit > Preferences > Asset Pipeline > Auto Refresh` 설정에서 옵션이 Enabled 혹은 Always Enabled로 되어 있는지 확인하세요. 만약 Disabled라면 스크립트를 고쳐도 유니티로 돌아왔을 때 반응이 없습니다.

-   컴파일 에러 확인 (Console창)

    -   스크립트에 문법 오류가 있으면 유니티는 새로운 코드 변경 사항을 적용하지 않고 이전 버전에 머물러 있습니다. 유니티 하단 상태 표시줄이나 Console 창에 빨간색 에러 메시지가 떠 있는지 확인하세요.

-   External Tools 설정 및 프로젝트 파일 재생성

    -   유니티와 VS Code 간의 연결이 끊어졌을 때 이런 문제가 발생할 수 있습니다.

    -   `Edit > Preferences > External Tools` 설정으로 가서 외부 에디터와의 연결 상태를 조정할 수 있습니다.
        1.  External Script Editor가 Visual Studio Code로 제대로 잡혀 있는지 확인합니다.
        2.  아래에 있는 Regenerate project files 버튼을 클릭하여 프로젝트 파일을 새로 고칩니다.

-   수동 새로고침 (Force Refresh)
    -   설정이 다 맞는데도 안 된다면 단축키로 강제 적용을 시도해 보세요.
    -   유니티 창을 클릭한 상태에서 Ctrl + R (macOS는 Cmd + R)을 누르면 에셋 데이터베이스를 강제로 새로 고칩니다.

## 기본 조작

-   시점 조작
    -   선택한 오브젝트로 시점 이동 F
    -   선택한 오브젝트 앵커 기준 횡이동 alt + 왼클릭
    -   선택한 오브젝트 앵커 기준 전후이동 alt + 우클릭

## 팁

### 네이밍 컨벤션

&nbsp; 따를 이유는 없으나 이름짓는데에 낭비되는 시간을 줄이기 위해 보통 다음의 규칙을 따릅니다.

-   대부분의 오브젝트 명은 파스칼케이스를 따릅니다.
-   단일 오브젝트의 동작, 조작 관리하며 대상 오브젝트(Player, Enemy, Camera)에 직접 붙어 있는 스크립트는 `오브젝트명Controller.cs` 로 명명합니다.
-   여러 오브젝트를 총괄하거나 시스템 전체의 흐름을 관리하는 싱글톤(Singleton) 객체에 붙는 스크립트는 `오브젝트명Manager.cs` 로 명명합니다.
-   public 이나 `[SerializeField]` 로 선언 시, 해당 오브젝트의 자료형 또는 클래스의 두문자어와 오브젝트명을 결합하여 `두문자_오브젝트명` 으로 명명합니다.
    -   예시) GameObject 클래스의 Cube 는 public GameObject go_Cube; 로 선언됩니다.

### Shortcut 오브젝트

&nbsp; \_Shortcut 이라는 작업용 오브젝트를 만들어 작업할 대상들을 찍어두면 작업이 편해집니다.

```cs
using UnityEngine;

public class Shortcut : MonoBehaviour {
    //<see href='file:///./Controller/PlayerController.cs'>ㄴㅇ</see>
    [Tooltip("Player 참조 변수")]
    [SerializeField] GameObject go_Player;
}
```

### 2D 스프라이트 이미지 적용이 안될 경우

-   해당 이미지 텍스처 타입이 `스프라이트(2D 및 UI)` 이며 스프라이트 모드가 `단일` 인지 확인해주세요.
-   유니티 6 버전부터 3D 개발시 2D 스프라이트 패키지를 자동설치해주지 않아서 설치가 안되어 있을 수 있습니다. 최상단 메뉴바에서 Window > Package Manager > Packages 를 Unity Registry 로 잡고 2D Sprite 패키지를 찾아 Install 해주세요.

### Unity Remote 5

&nbsp; 휴대폰에서 프로젝트 테스트를 빌드 없이 하게 도와주는 앱입니다.

-   스마트폰에 Unity Remote 5 앱을 설치하고 USB로 PC와 연결하세요.
-   Edit > Project Settings > Editor > Device에서 연결된 기기를 선택하면, 휴대폰에서 터치하는 입력이 에디터로 실시간 전달됩니다.

## 양식

### 양식/터치 시스템

&nbsp; 리뉴얼된 InputSystem.EnhancedTouch.Touch; 기반으로 다음과 같이 작성합니다.

-   캔버스 위의 UI 객체들은 Raycast Target 설정이 켜져있어야 인식됩니다.
-   게임 화면의 게임오브젝트들은 Collider 설정값이 있어야 인식됩니다.

```cs
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.EnhancedTouch;
// * UnityEngine.Touch와 충돌 방지
using Touch = UnityEngine.InputSystem.EnhancedTouch.Touch;
using UnityEngine.EventSystems;
using System.Collections.Generic;

public class PlayerController : MonoBehaviour {
    // ### Variable =================================================

    [Tooltip("메인 카메라 오브젝트를 할당해주어야 합니다.")]
    [SerializeField] private Camera mainCamera;

    // ### Methods ==================================================
    private void HandleTouch(Vector2 screenPosition)
    {

        // * UI touch
        {
            // * eventData 에 screenPosition 대입
            // * using UnityEngine.EventSystems; 선언 필요
            PointerEventData eventData = new PointerEventData(EventSystem.current);
            eventData.position = screenPosition;

            // * 레이캐스트에 맞은 UI 오브젝트를 담은 List
            // * using System.Collections.Generic; 선언 필요
            List<RaycastResult> results = new List<RaycastResult>();

            // * UI 레이캐스트 실행 -> 결과물은 results 에
            EventSystem.current.RaycastAll(eventData, results);

            if (results.Count > 0) {
                // * 가장 상단에 있는 UI의 이름을 출력 (results[0])
                Debug.Log($"<color=yellow>Hit UI: {results[0].gameObject.name}</color>");
                return;
            }
        }

        // * Game Scene touch
        {
            // * 터치 지점에서 레이(Ray)를 쏩니다.
            Ray ray = mainCamera.ScreenPointToRay(screenPosition);
            RaycastHit hit;

            if (Physics.Raycast(ray, out hit)) {
                Debug.Log($"<color=#FF0000>Hit Object: {hit.collider.name}</color>");

                // * 터치된 오브젝트에 특정 컴포넌트가 있는지 확인
                if (hit.collider.TryGetComponent<BubbleController>(out BubbleController bubble)) {
                    bubble.Pop();
                }
            }
        }
    }

    // ### Life Cycle ===============================================

    void OnEnable() {
        // * EnhancedTouch를 활성화해야 멀티터치 추적이 가능합니다.
        EnhancedTouchSupport.Enable();
    }

    void Update() {
        // 터치된 모든 손가락을 순회한다.
        int cnt = 0;
        foreach (var touch in Touch.activeTouches) {
            cnt++;
            // 터치가 막 시작된 프레임(Began)에만 실행
            if (touch.began) {
                Vector2 touchPos = touch.screenPosition;
                Debug.Log($"[TOUCH POS:{cnt}] x:{touchPos.x}, y:{touchPos.y}");
                HandleTouch(touch.screenPosition);
            }
        }

        // 마우스 입력을 체크한다.
        if (Mouse.current.leftButton.wasPressedThisFrame) {
            Vector2 mousePos = Mouse.current.position.ReadValue();
            Debug.Log($"[MOUSE POS] x:{mousePos.x}, y:{mousePos.y}");
            HandleTouch(mousePos);
        }
    }

    void OnDisable() {
        EnhancedTouchSupport.Disable();
    }
}
```

### 양식/비주얼 노벨：Form/Visual Novel Genre
